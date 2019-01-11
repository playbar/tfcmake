// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_FUNCTIONAL_OPS_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_FUNCTIONAL_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

/// @defgroup functional_ops Functional Ops
/// @{

///   ```python
///    output = input;
///    for i in range(start, limit, delta)
///      output = body(i, output);
///   ```
///
/// Arguments:
/// * scope: A Scope object
/// * start: The lower bound. An int32
/// * limit: The upper bound. An int32
/// * delta: The increment. An int32
/// * input: A list of input tensors whose types are T.
/// * body:     A function that takes a list of tensors (int32, T) and returns another
///     list of tensors (T).
///
/// Returns:
/// * `OutputList`: A list of output tensors whose types are T.
class For {
 public:
  For(const ::tensorflow::Scope& scope, ::tensorflow::Input start,
    ::tensorflow::Input limit, ::tensorflow::Input delta,
    ::tensorflow::InputList input, const NameAttrList& body);
  ::tensorflow::Output operator[](size_t index) const { return output[index]; }


  ::tensorflow::OutputList output;
};

/// output = cond ? then_branch(input) : else_branch(input)
///
/// Arguments:
/// * scope: A Scope object
/// * cond:       A Tensor. If the tensor is a scalar of non-boolean type, the
///       scalar is converted to a boolean according to the
///       following rule: if the scalar is a numerical value, non-zero means
///       `True` and zero means False; if the scalar is a string, non-empty
///       means `True` and empty means `False`. If the tensor is not a scalar,
///       being empty means False and being non-empty means True.
/// * input: A list of input tensors.
/// * Tout: A list of output types.
/// * then_branch:       A function that takes 'inputs' and returns a list of tensors, whose
///       types are the same as what else_branch returns.
/// * else_branch:     A function that takes 'inputs' and returns a list of tensors, whose
///     types are the same as what then_branch returns.
///
/// Returns:
/// * `OutputList`: A list of return values.
class If {
 public:
  If(const ::tensorflow::Scope& scope, ::tensorflow::Input cond,
   ::tensorflow::InputList input, const DataTypeSlice& Tout, const
   NameAttrList& then_branch, const NameAttrList& else_branch);
  ::tensorflow::Output operator[](size_t index) const { return output[index]; }


  ::tensorflow::OutputList output;
};

/// returns `f(inputs)`, where `f`'s body is placed and partitioned.
///
/// Arguments:
/// * scope: A Scope object
/// * args: A list of input tensors.
/// * Tout: A list of output types.
/// * f:       A function that takes 'args', a list of tensors, and returns 'output',
///       another list of tensors. Input and output types are specified by 'Tin'
///       and 'Tout'. The function body of f will be placed and partitioned across
///       devices, setting this op apart from the regular Call op.
///
/// Returns:
/// * `OutputList`: A list of return values.
class PartitionedCall {
 public:
  PartitionedCall(const ::tensorflow::Scope& scope, ::tensorflow::InputList args,
                const DataTypeSlice& Tout, const NameAttrList& f);
  ::tensorflow::Output operator[](size_t index) const { return output[index]; }


  ::tensorflow::OutputList output;
};

/// Runs function `f` on a remote device indicated by `target`.
///
/// Arguments:
/// * scope: A Scope object
/// * target: A fully specified device name where we want to run the function.
/// * args: A list of arguments for the function.
/// * Tout: The type list for the return values.
/// * f: The function to run remotely.
///
/// Returns:
/// * `OutputList`: A list of return values.
class RemoteCall {
 public:
  RemoteCall(const ::tensorflow::Scope& scope, ::tensorflow::Input target,
           ::tensorflow::InputList args, const DataTypeSlice& Tout, const
           NameAttrList& f);
  ::tensorflow::Output operator[](size_t index) const { return output[index]; }


  ::tensorflow::OutputList output;
};

/// Computes the gradient function for function f via backpropagation.
///
/// Arguments:
/// * scope: A Scope object
/// * input: a list of input tensors of size N + M;
/// * Tout: the type list for the input list.
/// * f: The function we want to compute the gradient for.
///
/// The function 'f' must be a numerical function which takes N inputs and
/// produces M outputs. Its gradient function 'g', which is computed by
/// this SymbolicGradient op is a function taking N + M inputs and
/// produces N outputs.
///
/// I.e. if we have
///    (y1, y2, ..., y_M) = f(x1, x2, ..., x_N),
/// then, g is
///    (dL/dx1, dL/dx2, ..., dL/dx_N) = g(x1, x2, ..., x_N,
///                                      dL/dy1, dL/dy2, ..., dL/dy_M),
///
/// where L is a scalar-value function of (x1, x2, ..., xN) (e.g., the
/// loss function). dL/dx_i is the partial derivative of L with respect
/// to x_i.
///
/// (Needs some math expert to say the comment above better.)
///
/// Returns:
/// * `OutputList`: a list of output tensors of size N;
class SymbolicGradient {
 public:
  SymbolicGradient(const ::tensorflow::Scope& scope, ::tensorflow::InputList
                 input, const DataTypeSlice& Tout, const NameAttrList& f);
  ::tensorflow::Output operator[](size_t index) const { return output[index]; }


  ::tensorflow::OutputList output;
};

/// output = input; While (Cond(output)) { output = Body(output) }
///
/// Arguments:
/// * scope: A Scope object
/// * input: A list of input tensors whose types are T.
/// * cond:       A function takes 'input' and returns a tensor.  If the tensor is
///       a scalar of non-boolean, the scalar is converted to a boolean
///       according to the following rule: if the scalar is a numerical
///       value, non-zero means True and zero means False; if the scalar is
///       a string, non-empty means True and empty means False. If the
///       tensor is not a scalar, non-emptiness means True and False
///       otherwise.
/// * body:       A function that takes a list of tensors and returns another
///       list of tensors. Both lists have the same types as specified
///       by T.
///
/// Returns:
/// * `OutputList`: A list of output tensors whose types are T.
class While {
 public:
  While(const ::tensorflow::Scope& scope, ::tensorflow::InputList input, const
      NameAttrList& cond, const NameAttrList& body);
  ::tensorflow::Output operator[](size_t index) const { return output[index]; }


  ::tensorflow::OutputList output;
};

/// @}

}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_FUNCTIONAL_OPS_H_
