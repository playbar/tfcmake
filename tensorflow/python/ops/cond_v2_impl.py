# Copyright 2018 The TensorFlow Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# =============================================================================
"""cond_v2 and gradient.

This is a version of cond that emits a single If op, as well as the gradient
function for If ops produced by cond_v2. This will eventually replace the
current tf.cond implementation once it reaches feature and performance parity.

NOTE: most users of cond_v2 should import cond_v2, not this module! This module
does not contain all the necessary imports to prevent circular dependencies,
while cond_v2 does.
"""

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

from tensorflow.core.framework import attr_value_pb2
from tensorflow.python import pywrap_tensorflow as c_api
from tensorflow.python.framework import c_api_util
from tensorflow.python.framework import ops
from tensorflow.python.ops import array_ops
from tensorflow.python.ops import control_flow_util
from tensorflow.python.ops import gen_functional_ops
from tensorflow.python.util import compat


# The following modules cannot be imported directly because they cause circular
# dependencies. These are set in each corresponding module.
_function = None
_function_def_to_graph = None
_gradients_impl = None

# NOTE(skyewm): TensorFlow uses protected class methods and fields to signify
# that they aren't part of the official public API. These protected members
# often need to be used by implementation code however. Rather than litter the
# code with pylint comments, we ignore protected access violations for
# readability.
# pylint: disable=protected-access


def cond_v2(pred, true_fn, false_fn, name="cond"):
  """Like tf.cond, except emits a single If op."""
  if not name:
    name = "cond"

  with ops.name_scope(name) as scope:
    # Identify if there is a caller device, & get the innermost if possible.
    device_stack = ops.get_default_graph()._device_function_stack
    caller_device = device_stack[-1] if device_stack else None

    caller_colocation_stack = ops.get_default_graph()._colocation_stack
    caller_container = ops.get_default_graph()._container
    caller_collection_ref = ops.get_default_graph()._collections

    func_name_prefix = scope.replace("/", "_")

    true_graph = _function.func_graph_from_py_func(
        true_fn, [], [],
        name="%strue" % func_name_prefix,
        device=caller_device,
        colocation_stack=caller_colocation_stack,
        collections_ref=caller_collection_ref,
        container=caller_container)
    false_graph = _function.func_graph_from_py_func(
        false_fn, [], [],
        name="%sfalse" % func_name_prefix,
        device=caller_device,
        colocation_stack=caller_colocation_stack,
        collections_ref=caller_collection_ref,
        container=caller_container)
    _check_same_outputs(true_graph, false_graph)

    # Add inputs to true_graph and false_graph to make them match. Note that
    # this modifies true_graph and false_graph.
    cond_inputs = _make_inputs_match(true_graph, false_graph,
                                     true_graph.extra_inputs,
                                     false_graph.extra_inputs)

    # Add all intermediate tensors as function outputs so they're available for
    # the gradient computation.

    true_intermediates = _get_intermediates(true_graph)
    false_intermediates = _get_intermediates(false_graph)

    # Save the original number of outputs to return to the caller.
    num_cond_outputs = len(true_graph.outputs)

    # Make the number/type of new intermediate outputs match.
    extra_true_outputs, extra_false_outputs = _pad_params(
        true_graph, false_graph, true_intermediates, false_intermediates)

    true_graph.outputs.extend(extra_true_outputs)
    false_graph.outputs.extend(extra_false_outputs)

    # Create the If op.
    tensors = gen_functional_ops._if(
        pred, cond_inputs, [t.dtype for t in true_graph.outputs],
        _create_new_tf_function(true_graph),
        _create_new_tf_function(false_graph),
        name=scope)

    # Set the flag to enable lowering on the `if` op if necessary
    # Lowering allows cond_v2 to avoid some of the limitations of Functions,
    # allowing users to specify devices & colocation inside of cond_v2 branches,
    # and enabling non-strict evaluation & partial pruning of cond_v2 branches.
    # This brings cond_v2 closer to feature parity with tf.cond.
    #
    # However, we do not lower `If` in the XLA context because it is easier for
    # XLA to apply its own optimizations when dealing with un-lowered `If`
    # operators than with lowered switch/merge control flow.
    #
    # TODO(b/110167197) this approach requires cond_v2 to have at least 1 output
    if_op = tensors[0].op
    if not control_flow_util.IsInXLAContext(if_op):
      if_op._set_attr("_lower_using_switch_merge",
                      attr_value_pb2.AttrValue(b=True))

    return tensors[:num_cond_outputs]


@ops.RegisterGradient("If")
def _IfGrad(op, *grads):  # pylint: disable=invalid-name
  """The gradient of an If op produced by cond_v2."""
  true_graph, false_graph = _get_func_graphs(op)
  # Note: op.graph != ops.get_default_graph() when we are computing the gradient
  # of a nested cond.
  assert true_graph._outer_graph == op.graph
  assert false_graph._outer_graph == op.graph

  # Create grad functions that compute the gradient of the true/false forward
  # graphs. These functions will capture tensors from the forward pass
  # functions.
  true_grad_graph = _create_grad_func(
      true_graph, grads, _get_grad_fn_name(true_graph))
  false_grad_graph = _create_grad_func(
      false_graph, grads, _get_grad_fn_name(false_graph))

  assert ([t.dtype for t in true_grad_graph.outputs] ==
          [t.dtype for t in false_grad_graph.outputs])

  # Resolve references to forward graph tensors in grad graphs and ensure
  # they are in-scope, i.e., belong to one of outer graphs of the grad graph.
  true_grad_extra_inputs = _resolve_grad_inputs(true_graph, true_grad_graph)
  false_grad_extra_inputs = _resolve_grad_inputs(false_graph, false_grad_graph)

  # Make the inputs to true_grad_graph and false_grad_graph match. Note that
  # this modifies true_grad_graph and false_grad_graph.
  grad_inputs = _make_inputs_match(true_grad_graph, false_grad_graph,
                                   true_grad_extra_inputs,
                                   false_grad_extra_inputs)

  # Add all intermediate tensors as function outputs so they're available for
  # higher-order gradient computations.

  true_grad_intermediates = _get_intermediates(true_grad_graph)
  false_grad_intermediates = _get_intermediates(false_grad_graph)

  # Save the original number of gradient outputs to return.
  num_grad_outputs = len(true_grad_graph.outputs)

  # Make the number/type of new intermediate outputs match.
  extra_true_grad_outputs, extra_false_grad_outputs = _pad_params(
      true_grad_graph, false_grad_graph,
      true_grad_intermediates, false_grad_intermediates)

  true_grad_graph.outputs.extend(extra_true_grad_outputs)
  false_grad_graph.outputs.extend(extra_false_grad_outputs)

  # Create the gradient If op.
  tensors = gen_functional_ops._if(
      op.inputs[0], grad_inputs, [t.dtype for t in true_grad_graph.outputs],
      _create_new_tf_function(true_grad_graph),
      _create_new_tf_function(false_grad_graph))

  # The predicate has no gradient.
  return [None] + tensors[:num_grad_outputs]


def _get_func_graphs(if_op):
  """Returns `_FuncGraph`s for the input op branches.

  Args:
    if_op: The _If Operation.

  Returns:
    A 2-tuple of the `_FuncGraph`s of the then_branch and else_branch.
  """
  def _get_func_graph_for_branch(branch_name):
    """Generates and returns a _FuncGraph for the given branch."""
    extra_inputs = if_op.inputs[1:]  # First input is pred.
    input_shapes = [t.shape for t in extra_inputs]
    func_name = if_op.get_attr(branch_name).name
    fdef = if_op.graph._get_function(func_name).definition
    # `if_op.graph` may not be the same as `ops.get_default_graph()` e.g.
    # in the case of nested if ops or when the gradient is being computed
    # from inside a Defun. We build the `func_graph` with `if_op.graph` as its
    # `outer_graph`. This resembles how the `_FuncGraph` was built in the
    # forward pass. We need this so that we can resolve references to tensors
    # in `func_graph` from its gradient graph in `_resolve_grad_inputs`.
    with if_op.graph.as_default():
      func_graph = _function_def_to_graph.function_def_to_graph(
          fdef, input_shapes)
    func_graph.extra_inputs = extra_inputs
    func_graph.extra_args = func_graph.inputs
    func_graph._captured = dict(zip(extra_inputs, func_graph.inputs))
    # Set the if op so that the gradient code can use it.
    func_graph._if = if_op
    return func_graph

  return (_get_func_graph_for_branch("then_branch"),
          _get_func_graph_for_branch("else_branch"))


def _grad_fn(func_graph, grads):
  """The gradient function for each conditional branch.

  This function builds the gradient graph of the corresponding forward-pass
  conditional branch in `func_graph`. This is done by differentiating
  func_graph's outputs w.r.t. its inputs.

  Args:
    func_graph: function._FuncGraph. The corresponding forward-pass function.
    grads: The list of input gradient Tensors.

  Returns:
    The output gradient Tensors.
  """
  # Filter out untrainable function outputs.
  # NOTE(skyewm): If we don't do this, the untrainable tensors can sometimes
  # cause _GradientsHelper to raise an exception (e.g. the implementation
  # doesn't expect 'ys' to contain boolean tensors).
  assert len(func_graph.outputs) == len(grads)
  ys = []
  grad_ys = []
  for y, grad_y in zip(func_graph.outputs, grads):
    if not _gradients_impl._IsTrainable(y):
      continue
    ys.append(y)
    grad_ys.append(grad_y)

  # Build the gradient graph. Note that this builds the gradient computation of
  # func_graph in the current graph, which requires capturing tensors from
  # func_graph. The captured func_graph tensors are resolved to external tensors
  # in _resolve_grad_inputs.
  result = _gradients_impl._GradientsHelper(
      ys, func_graph.inputs, grad_ys=grad_ys,
      src_graph=func_graph)

  # Functions can't return None; replace Nones with zero tensors.
  # TODO(b/80444525): don't return anything here and make _IfGrad return None if
  # both branches have zero gradient.
  for i in range(len(result)):
    if result[i] is None:
      result[i] = array_ops.zeros_like(func_graph.inputs[i])

  return result


def _create_grad_func(func_graph, grads, name):
  """Returns the _FuncGraph representation of _grad_fn."""
  return _function.func_graph_from_py_func(lambda: _grad_fn(func_graph, grads),
                                           [], [], name)


def _resolve_grad_inputs(cond_graph, grad_graph):
  """Returns the tensors to pass as `extra_inputs` to `grad_graph`.

  The `grad_graph` may have external references to
  1. Its outer graph containing the input gradients. These references are kept
     as is.
  2. Tensors in the forward pass graph. These tensors may not be "live"
     when the gradient is being computed. We replace such references by their
     corresponding tensor in the least common ancestor graph of `grad_graph` and
     `cond_graph`. Since we export intermediate tensors for all branch
     functions, this is always possible.

  Args:
    cond_graph: function._FuncGraph. The forward-pass function.
    grad_graph: function._FuncGraph. The gradients function.

  Returns:
    A list of inputs tensors to be passed to grad_graph.
  """
  new_extra_inputs = []

  for t in grad_graph.extra_inputs:
    if t.graph != grad_graph._outer_graph:
      # `t` is a tensor in `cond_graph` or one of its ancestors. We bubble this
      # tensor to the least common ancestor of the `cond_graph` and
      # `grad_graph` so that it is "in-scope" for `grad_graph`.
      # TODO(srbs): `_is_ancestor` calls may be expensive. Compute the least
      # common ancestor once and re-use.
      assert _is_ancestor(cond_graph, t.graph)
      while not _is_ancestor(grad_graph, t.graph):
        assert isinstance(t.graph, _function._FuncGraph)
        if t in t.graph.extra_args:
          # TODO(srbs): Consider building a map of extra_args -> extra_inputs.
          # instead of searching for `t` twice.
          t = t.graph.extra_inputs[t.graph.extra_args.index(t)]
        else:
          # Note: All intermediate tensors are output by the If op.
          # TODO(srbs): .index() calls may be expensive. Optimize.
          t = t.graph._if.outputs[t.graph.outputs.index(t)]
      assert _is_ancestor(grad_graph, t.graph)
    new_extra_inputs.append(t)

  return new_extra_inputs


def _create_new_tf_function(func_graph):
  """Converts func_graph to a TF_Function and adds it to the current graph.

  Args:
    func_graph: function._FuncGraph

  Returns:
    The name of the new TF_Function.
  """
  c_func = c_api.TF_GraphToFunction_wrapper(
      func_graph._c_graph,
      compat.as_str(func_graph.name),
      False,  # append_hash_to_fn_name
      None,  # opers
      [t._as_tf_output() for t in func_graph.inputs],
      [t._as_tf_output() for t in func_graph.outputs],
      [],
      None,  # opts
      None)  # description
  _ = c_api_util.ScopedTFFunction(c_func)

  # TODO(b/109833212): this sucks, we're serializing the TF_Function*,
  # deserializing it into a Python FunctionDef, then reserializing it to create
  # a new TF_Function that we add to the graph.
  fdef = _function.function_def_from_tf_function(c_func)
  defined_func = _function._from_definition(fdef)
  defined_func._sub_functions = func_graph._functions
  defined_func.add_to_graph(func_graph._outer_graph)

  return func_graph.name


def _get_intermediates(func_graph):
  """Returns all tensors in `func_graph` that aren't inputs or outputs."""
  intermediates = []
  for op in func_graph.get_operations():
    for t in op.outputs:
      if t in func_graph.inputs: continue
      if t in func_graph.outputs: continue
      intermediates.append(t)
  return intermediates


def _separate_unique_inputs(true_inputs, false_inputs):
  """Separates tensors appearing only in true_inputs or false_inputs, or both.

  Args:
    true_inputs: list of Tensors
    false_inputs: list of Tensors

  Returns:
    Three lists of Tensors:
      1. The tensors that appear in both true_inputs and false_inputs
      2. The tensors that only appear in true_inputs
      3. The tensors that only appear in false_inputs
  """
  true_inputs = set(true_inputs)
  false_inputs = set(false_inputs)

  shared_inputs = true_inputs.intersection(false_inputs)
  true_only_inputs = true_inputs - false_inputs
  false_only_inputs = false_inputs - true_inputs

  return list(shared_inputs), list(true_only_inputs), list(false_only_inputs)


def _pad_params(true_graph, false_graph, true_params, false_params):
  """Returns new param lists that have matching signatures.

  This is done by mirroring each param list in the other using dummy params.
  There is no merging of params.

  Args:
    true_graph: function._FuncGraph
    false_graph: function._FuncGraph
    true_params: a list of Tensors from true_graph
    false_params: a list of Tensors from false_graph

  Returns:
    A new list of Tensors in true_graph and a new list of Tensors in
    false_graph. The two lists have the same number of Tensors, with matching
    types and shapes across the lists.
  """
  new_true_params = (true_params +
                     _create_dummy_params(true_graph, false_params))
  new_false_inputs = (_create_dummy_params(false_graph, true_params)
                      + false_params)
  return new_true_params, new_false_inputs


def _make_inputs_match(true_graph, false_graph, true_extra_inputs,
                       false_extra_inputs):
  """Modifies true_graph and false_graph so they have the same input signature.

  This method reorders and/or adds parameters to true_graph and false_graph so
  they have the same input signature, and updates the 'inputs', 'extra_inputs',
  and '_captured' fields of both graphs accordingly. It uses the input tensors
  from the outer graph to avoid duplicating shared arguments.

  Args:
    true_graph: function._FuncGraph
    false_graph: function._FuncGraph
    true_extra_inputs: a list of Tensors in the outer graph. The inputs for
      true_graph.
    false_extra_inputs: a list of Tensors in the outer graph. The inputs for
      false_graph.

  Returns:
    A new list of Tensors from the outer graph that are the new inputs for both
    true_graph and false_graph. This is a deduped version of true_inputs +
    false_inputs.
  """
  shared_inputs, true_only_inputs, false_only_inputs = _separate_unique_inputs(
      true_extra_inputs, false_extra_inputs)

  new_inputs = shared_inputs + true_only_inputs + false_only_inputs

  true_input_to_param = dict(zip(true_extra_inputs, true_graph.inputs))
  false_input_to_param = dict(zip(false_extra_inputs, false_graph.inputs))

  true_graph.inputs = (
      [true_input_to_param[t] for t in shared_inputs] +
      [true_input_to_param[t] for t in true_only_inputs] +
      _create_dummy_params(true_graph, false_only_inputs))

  false_graph.inputs = (
      [false_input_to_param[t] for t in shared_inputs] +
      _create_dummy_params(false_graph, true_only_inputs) +
      [false_input_to_param[t] for t in false_only_inputs])

  # Rewrite the _FuncGraphs' state to reflect the new inputs.
  true_graph.extra_inputs = new_inputs
  false_graph.extra_inputs = new_inputs

  true_graph.extra_args = true_graph.inputs
  false_graph.extra_args = false_graph.inputs

  true_graph._captured = dict(zip(new_inputs, true_graph.inputs))
  false_graph._captured = dict(zip(new_inputs, false_graph.inputs))

  return new_inputs


def _create_dummy_params(func_graph, template_tensors):
  """Creates tensors in func_graph to represent template_tensors.

  Args:
    func_graph: function._FuncGraph.
    template_tensors: a list of tensors in the outer graph.

  Returns:
    A list of tensors in func_graph.
  """
  with func_graph.as_default():
    return [gen_functional_ops.fake_param(dtype=t.dtype, shape=t.shape)
            for t in template_tensors]


def _get_grad_fn_name(func_graph):
  """Returns a unique name to use for the grad function of `func_graph`.

  Ensures this name is unique in the entire hierarchy.

  Args:
    func_graph: The _FuncGraph.

  Returns:
    A string, the name to use for the gradient function.
  """
  name = "%s_grad" % func_graph.name

  base_name = name
  counter = 1
  has_conflict = True
  while has_conflict:
    curr_graph = func_graph._outer_graph
    has_conflict = curr_graph._is_function(name)
    while not has_conflict and isinstance(curr_graph, _function._FuncGraph):
      curr_graph = curr_graph._outer_graph
      has_conflict = curr_graph._is_function(name)
    if has_conflict:
      name = "%s_%s" % (base_name, counter)
      counter += 1

  return name


def _check_same_outputs(true_graph, false_graph):
  """Raises an error if true_graph and false_graph have different outputs."""
  true_output_types = [t.dtype for t in true_graph.outputs]
  false_output_types = [t.dtype for t in false_graph.outputs]
  if (len(true_graph.outputs) != len(false_graph.outputs) or
      true_output_types != false_output_types):
    raise ValueError(
        "true_fn() and false_fn() must return the same number and type of "
        "arguments, got:\n"
        "  true_fn: %s\n"
        "  false_fn: %s" % (true_output_types, false_output_types))


def _is_ancestor(graph, maybe_ancestor):
  if maybe_ancestor == graph:
    return True
  if isinstance(graph, _function._FuncGraph):
    return _is_ancestor(graph._outer_graph, maybe_ancestor)
  return False
