// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_RESOURCE_VARIABLE_OPS_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_RESOURCE_VARIABLE_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

/// @defgroup resource_variable_ops Resource Variable Ops
/// @{

/// Adds a value to the current value of a variable.
///
/// Any ReadVariableOp with a control dependency on this op is guaranteed to
/// see the incremented value or a subsequent newer one.
///
/// Arguments:
/// * scope: A Scope object
/// * resource: handle to the resource in which to store the variable.
/// * value: the value by which the variable will be incremented.
///
/// Returns:
/// * the created `Operation`
class AssignAddVariableOp {
 public:
  AssignAddVariableOp(const ::tensorflow::Scope& scope, ::tensorflow::Input
                    resource, ::tensorflow::Input value);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Subtracts a value from the current value of a variable.
///
/// Any ReadVariableOp with a control dependency on this op is guaranteed to
/// see the decremented value or a subsequent newer one.
///
/// Arguments:
/// * scope: A Scope object
/// * resource: handle to the resource in which to store the variable.
/// * value: the value by which the variable will be incremented.
///
/// Returns:
/// * the created `Operation`
class AssignSubVariableOp {
 public:
  AssignSubVariableOp(const ::tensorflow::Scope& scope, ::tensorflow::Input
                    resource, ::tensorflow::Input value);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Assigns a new value to a variable.
///
/// Any ReadVariableOp with a control dependency on this op is guaranteed to return
/// this value or a subsequent newer value of the variable.
///
/// Arguments:
/// * scope: A Scope object
/// * resource: handle to the resource in which to store the variable.
/// * value: the value to set the new tensor to use.
///
/// Returns:
/// * the created `Operation`
class AssignVariableOp {
 public:
  AssignVariableOp(const ::tensorflow::Scope& scope, ::tensorflow::Input
                 resource, ::tensorflow::Input value);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// This op consumes a lock created by `MutexLock`.
///
/// This op exists to consume a tensor created by `MutexLock` (other than
/// direct control dependencies).  It should be the only that consumes the tensor,
/// and will raise an error if it is not.  Its only purpose is to keep the
/// mutex lock tensor alive until it is consumed by this op.
///
/// **NOTE**: This operation must run on the same device as its input.  This may
/// be enforced via the `colocate_with` mechanism.
///
/// Arguments:
/// * scope: A Scope object
/// * mutex_lock: A tensor returned by `MutexLock`.
///
/// Returns:
/// * the created `Operation`
class ConsumeMutexLock {
 public:
  ConsumeMutexLock(const ::tensorflow::Scope& scope, ::tensorflow::Input
                 mutex_lock);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Deletes the resource specified by the handle.
///
/// All subsequent operations using the resource will result in a NotFound
/// error status.
///
/// Arguments:
/// * scope: A Scope object
/// * resource: handle to the resource to delete.
///
/// Optional attributes (see `Attrs`):
/// * ignore_lookup_error: whether to ignore the error when the resource
/// doesn't exist.
///
/// Returns:
/// * the created `Operation`
class DestroyResourceOp {
 public:
  /// Optional attribute setters for DestroyResourceOp
  struct Attrs {
    /// whether to ignore the error when the resource
    /// doesn't exist.
    ///
    /// Defaults to true
    TF_MUST_USE_RESULT Attrs IgnoreLookupError(bool x) {
      Attrs ret = *this;
      ret.ignore_lookup_error_ = x;
      return ret;
    }

    bool ignore_lookup_error_ = true;
  };
  DestroyResourceOp(const ::tensorflow::Scope& scope, ::tensorflow::Input
                  resource);
  DestroyResourceOp(const ::tensorflow::Scope& scope, ::tensorflow::Input
                  resource, const DestroyResourceOp::Attrs& attrs);
  operator ::tensorflow::Operation() const { return operation; }

  static Attrs IgnoreLookupError(bool x) {
    return Attrs().IgnoreLookupError(x);
  }

  Operation operation;
};

/// Locks a mutex resource.  The output is the lock.  So long as the lock tensor
///
/// is alive, any other request to use `MutexLock` with this mutex will wait.
///
/// This is particularly useful for creating a critical section when used in
/// conjunction with `MutexLockIdentity`:
///
/// ```python
///
/// mutex = mutex_v2(
///   shared_name=handle_name, container=container, name=name)
///
/// def execute_in_critical_section(fn, *args, **kwargs):
///   lock = gen_resource_variable_ops.mutex_lock(mutex)
///
///   with ops.control_dependencies([lock]):
///     r = fn(*args, **kwargs)
///
///   with ops.control_dependencies(nest.flatten(r)):
///     with ops.colocate_with(mutex):
///       ensure_lock_exists = mutex_lock_identity(lock)
///
///     # Make sure that if any element of r is accessed, all of
///     # them are executed together.
///     r = nest.map_structure(tf.identity, r)
///
///   with ops.control_dependencies([ensure_lock_exists]):
///     return nest.map_structure(tf.identity, r)
/// ```
///
/// While `fn` is running in the critical section, no other functions which wish to
/// use this critical section may run.
///
/// Often the use case is that two executions of the same graph, in parallel,
/// wish to run `fn`; and we wish to ensure that only one of them executes
/// at a time.  This is especially important if `fn` modifies one or more
/// variables at a time.
///
/// It is also useful if two separate functions must share a resource, but we
/// wish to ensure the usage is exclusive.
///
/// Arguments:
/// * scope: A Scope object
/// * mutex: The mutex resource to lock.
///
/// Returns:
/// * `Output`: A tensor that keeps a shared pointer to a lock on the mutex;
/// when the Tensor is destroyed, the use count on the shared pointer is decreased
/// by 1.  When it reaches 0, the lock is released.
class MutexLock {
 public:
  MutexLock(const ::tensorflow::Scope& scope, ::tensorflow::Input mutex);
  operator ::tensorflow::Output() const { return mutex_lock; }
  operator ::tensorflow::Input() const { return mutex_lock; }
  ::tensorflow::Node* node() const { return mutex_lock.node(); }

  ::tensorflow::Output mutex_lock;
};

/// Creates a Mutex resource that can be locked by `MutexLock`.
///
/// Arguments:
/// * scope: A Scope object
///
/// Optional attributes (see `Attrs`):
/// * container: If non-empty, this variable is placed in the given container.
/// Otherwise, a default container is used.
/// * shared_name: If non-empty, this variable is named in the given bucket
/// with this shared_name. Otherwise, the node name is used instead.
///
/// Returns:
/// * `Output`: The mutex resource.
class MutexV2 {
 public:
  /// Optional attribute setters for MutexV2
  struct Attrs {
    /// If non-empty, this variable is placed in the given container.
    /// Otherwise, a default container is used.
    ///
    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs Container(StringPiece x) {
      Attrs ret = *this;
      ret.container_ = x;
      return ret;
    }

    /// If non-empty, this variable is named in the given bucket
    /// with this shared_name. Otherwise, the node name is used instead.
    ///
    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs SharedName(StringPiece x) {
      Attrs ret = *this;
      ret.shared_name_ = x;
      return ret;
    }

    StringPiece container_ = "";
    StringPiece shared_name_ = "";
  };
  MutexV2(const ::tensorflow::Scope& scope);
  MutexV2(const ::tensorflow::Scope& scope, const MutexV2::Attrs& attrs);
  operator ::tensorflow::Output() const { return resource; }
  operator ::tensorflow::Input() const { return resource; }
  ::tensorflow::Node* node() const { return resource.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::Output resource;
};

/// Reads the value of a variable.
///
/// The tensor returned by this operation is immutable.
///
/// The value returned by this operation is guaranteed to be influenced by all the
/// writes on which this operation depends directly or indirectly, and to not be
/// influenced by any of the writes which depend directly or indirectly on this
/// operation.
///
/// Arguments:
/// * scope: A Scope object
/// * resource: handle to the resource in which to store the variable.
/// * dtype: the dtype of the value.
///
/// Returns:
/// * `Output`: The value tensor.
class ReadVariableOp {
 public:
  ReadVariableOp(const ::tensorflow::Scope& scope, ::tensorflow::Input resource,
               DataType dtype);
  operator ::tensorflow::Output() const { return value; }
  operator ::tensorflow::Input() const { return value; }
  ::tensorflow::Node* node() const { return value.node(); }

  ::tensorflow::Output value;
};

/// Gather slices from the variable pointed to by `resource` according to `indices`.
///
/// `indices` must be an integer tensor of any dimension (usually 0-D or 1-D).
/// Produces an output tensor with shape `indices.shape + params.shape[1:]` where:
///
/// ```python
///     # Scalar indices
///     output[:, ..., :] = params[indices, :, ... :]
///
///     # Vector indices
///     output[i, :, ..., :] = params[indices[i], :, ... :]
///
///     # Higher rank indices
///     output[i, ..., j, :, ... :] = params[indices[i, ..., j], :, ..., :]
/// ```
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The output tensor.
class ResourceGather {
 public:
  /// Optional attribute setters for ResourceGather
  struct Attrs {
    /// Defaults to true
    TF_MUST_USE_RESULT Attrs ValidateIndices(bool x) {
      Attrs ret = *this;
      ret.validate_indices_ = x;
      return ret;
    }

    bool validate_indices_ = true;
  };
  ResourceGather(const ::tensorflow::Scope& scope, ::tensorflow::Input resource,
               ::tensorflow::Input indices, DataType dtype);
  ResourceGather(const ::tensorflow::Scope& scope, ::tensorflow::Input resource,
               ::tensorflow::Input indices, DataType dtype, const
               ResourceGather::Attrs& attrs);
  operator ::tensorflow::Output() const { return output; }
  operator ::tensorflow::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs ValidateIndices(bool x) {
    return Attrs().ValidateIndices(x);
  }

  ::tensorflow::Output output;
};

/// Adds sparse updates to the variable referenced by `resource`.
///
/// This operation computes
///
///     # Scalar indices
///     ref[indices, ...] += updates[...]
///
///     # Vector indices (for each i)
///     ref[indices[i], ...] += updates[i, ...]
///
///     # High rank indices (for each i, ..., j)
///     ref[indices[i, ..., j], ...] += updates[i, ..., j, ...]
///
/// Duplicate entries are handled correctly: if multiple `indices` reference
/// the same location, their contributions add.
///
/// Requires `updates.shape = indices.shape + ref.shape[1:]` or `updates.shape = []`.
///
/// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
/// <img style="width:100%" src='https://www.tensorflow.org/images/ScatterAdd.png' alt>
/// </div>
///
/// Arguments:
/// * scope: A Scope object
/// * resource: Should be from a `Variable` node.
/// * indices: A tensor of indices into the first dimension of `ref`.
/// * updates: A tensor of updated values to add to `ref`.
///
/// Returns:
/// * the created `Operation`
class ResourceScatterAdd {
 public:
  ResourceScatterAdd(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   resource, ::tensorflow::Input indices, ::tensorflow::Input
                   updates);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Divides sparse updates into the variable referenced by `resource`.
///
/// This operation computes
///
///     # Scalar indices
///     ref[indices, ...] /= updates[...]
///
///     # Vector indices (for each i)
///     ref[indices[i], ...] /= updates[i, ...]
///
///     # High rank indices (for each i, ..., j)
///     ref[indices[i, ..., j], ...] /= updates[i, ..., j, ...]
///
/// Duplicate entries are handled correctly: if multiple `indices` reference
/// the same location, their contributions multiply.
///
/// Requires `updates.shape = indices.shape + ref.shape[1:]` or `updates.shape = []`.
///
/// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
/// <img style="width:100%" src='https://www.tensorflow.org/images/ScatterAdd.png' alt>
/// </div>
///
/// Arguments:
/// * scope: A Scope object
/// * resource: Should be from a `Variable` node.
/// * indices: A tensor of indices into the first dimension of `ref`.
/// * updates: A tensor of updated values to add to `ref`.
///
/// Returns:
/// * the created `Operation`
class ResourceScatterDiv {
 public:
  ResourceScatterDiv(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   resource, ::tensorflow::Input indices, ::tensorflow::Input
                   updates);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Reduces sparse updates into the variable referenced by `resource` using the `max` operation.
///
/// This operation computes
///
///     # Scalar indices
///     ref[indices, ...] = max(ref[indices, ...], updates[...])
///
///     # Vector indices (for each i)
///     ref[indices[i], ...] = max(ref[indices[i], ...], updates[i, ...])
///
///     # High rank indices (for each i, ..., j)
///     ref[indices[i, ..., j], ...] = max(ref[indices[i, ..., j], ...], updates[i, ..., j, ...])
///
/// Duplicate entries are handled correctly: if multiple `indices` reference
/// the same location, their contributions are combined.
///
/// Requires `updates.shape = indices.shape + ref.shape[1:]` or `updates.shape = []`.
///
/// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
/// <img style="width:100%" src='https://www.tensorflow.org/images/ScatterAdd.png' alt>
/// </div>
///
/// Arguments:
/// * scope: A Scope object
/// * resource: Should be from a `Variable` node.
/// * indices: A tensor of indices into the first dimension of `ref`.
/// * updates: A tensor of updated values to add to `ref`.
///
/// Returns:
/// * the created `Operation`
class ResourceScatterMax {
 public:
  ResourceScatterMax(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   resource, ::tensorflow::Input indices, ::tensorflow::Input
                   updates);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Reduces sparse updates into the variable referenced by `resource` using the `min` operation.
///
/// This operation computes
///
///     # Scalar indices
///     ref[indices, ...] = min(ref[indices, ...], updates[...])
///
///     # Vector indices (for each i)
///     ref[indices[i], ...] = min(ref[indices[i], ...], updates[i, ...])
///
///     # High rank indices (for each i, ..., j)
///     ref[indices[i, ..., j], ...] = min(ref[indices[i, ..., j], ...], updates[i, ..., j, ...])
///
/// Duplicate entries are handled correctly: if multiple `indices` reference
/// the same location, their contributions are combined.
///
/// Requires `updates.shape = indices.shape + ref.shape[1:]` or `updates.shape = []`.
///
/// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
/// <img style="width:100%" src='https://www.tensorflow.org/images/ScatterAdd.png' alt>
/// </div>
///
/// Arguments:
/// * scope: A Scope object
/// * resource: Should be from a `Variable` node.
/// * indices: A tensor of indices into the first dimension of `ref`.
/// * updates: A tensor of updated values to add to `ref`.
///
/// Returns:
/// * the created `Operation`
class ResourceScatterMin {
 public:
  ResourceScatterMin(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   resource, ::tensorflow::Input indices, ::tensorflow::Input
                   updates);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Multiplies sparse updates into the variable referenced by `resource`.
///
/// This operation computes
///
///     # Scalar indices
///     ref[indices, ...] *= updates[...]
///
///     # Vector indices (for each i)
///     ref[indices[i], ...] *= updates[i, ...]
///
///     # High rank indices (for each i, ..., j)
///     ref[indices[i, ..., j], ...] *= updates[i, ..., j, ...]
///
/// Duplicate entries are handled correctly: if multiple `indices` reference
/// the same location, their contributions multiply.
///
/// Requires `updates.shape = indices.shape + ref.shape[1:]` or `updates.shape = []`.
///
/// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
/// <img style="width:100%" src='https://www.tensorflow.org/images/ScatterAdd.png' alt>
/// </div>
///
/// Arguments:
/// * scope: A Scope object
/// * resource: Should be from a `Variable` node.
/// * indices: A tensor of indices into the first dimension of `ref`.
/// * updates: A tensor of updated values to add to `ref`.
///
/// Returns:
/// * the created `Operation`
class ResourceScatterMul {
 public:
  ResourceScatterMul(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   resource, ::tensorflow::Input indices, ::tensorflow::Input
                   updates);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Subtracts sparse updates from the variable referenced by `resource`.
///
/// This operation computes
///
///     # Scalar indices
///     ref[indices, ...] -= updates[...]
///
///     # Vector indices (for each i)
///     ref[indices[i], ...] -= updates[i, ...]
///
///     # High rank indices (for each i, ..., j)
///     ref[indices[i, ..., j], ...] -= updates[i, ..., j, ...]
///
/// Duplicate entries are handled correctly: if multiple `indices` reference
/// the same location, their contributions add.
///
/// Requires `updates.shape = indices.shape + ref.shape[1:]` or `updates.shape = []`.
///
/// <div style="width:70%; margin:auto; margin-bottom:10px; margin-top:20px;">
/// <img style="width:100%" src='https://www.tensorflow.org/images/ScatterAdd.png' alt>
/// </div>
///
/// Arguments:
/// * scope: A Scope object
/// * resource: Should be from a `Variable` node.
/// * indices: A tensor of indices into the first dimension of `ref`.
/// * updates: A tensor of updated values to add to `ref`.
///
/// Returns:
/// * the created `Operation`
class ResourceScatterSub {
 public:
  ResourceScatterSub(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   resource, ::tensorflow::Input indices, ::tensorflow::Input
                   updates);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Assigns sparse updates to the variable referenced by `resource`.
///
/// This operation computes
///
///     # Scalar indices
///     ref[indices, ...] = updates[...]
///
///     # Vector indices (for each i)
///     ref[indices[i], ...] = updates[i, ...]
///
///     # High rank indices (for each i, ..., j)
///     ref[indices[i, ..., j], ...] = updates[i, ..., j, ...]
///
/// Arguments:
/// * scope: A Scope object
/// * resource: Should be from a `Variable` node.
/// * indices: A tensor of indices into the first dimension of `ref`.
/// * updates: A tensor of updated values to add to `ref`.
///
/// Returns:
/// * the created `Operation`
class ResourceScatterUpdate {
 public:
  ResourceScatterUpdate(const ::tensorflow::Scope& scope, ::tensorflow::Input
                      resource, ::tensorflow::Input indices,
                      ::tensorflow::Input updates);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Creates a handle to a Variable resource.
///
/// Arguments:
/// * scope: A Scope object
/// * dtype: the type of this variable. Must agree with the dtypes
/// of all ops using this variable.
/// * shape: The (possibly partially specified) shape of this variable.
///
/// Optional attributes (see `Attrs`):
/// * container: the container this variable is placed in.
/// * shared_name: the name by which this variable is referred to.
///
/// Returns:
/// * `Output`: The resource tensor.
class VarHandleOp {
 public:
  /// Optional attribute setters for VarHandleOp
  struct Attrs {
    /// the container this variable is placed in.
    ///
    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs Container(StringPiece x) {
      Attrs ret = *this;
      ret.container_ = x;
      return ret;
    }

    /// the name by which this variable is referred to.
    ///
    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs SharedName(StringPiece x) {
      Attrs ret = *this;
      ret.shared_name_ = x;
      return ret;
    }

    StringPiece container_ = "";
    StringPiece shared_name_ = "";
  };
  VarHandleOp(const ::tensorflow::Scope& scope, DataType dtype,
            PartialTensorShape shape);
  VarHandleOp(const ::tensorflow::Scope& scope, DataType dtype,
            PartialTensorShape shape, const VarHandleOp::Attrs& attrs);
  operator ::tensorflow::Output() const { return resource; }
  operator ::tensorflow::Input() const { return resource; }
  ::tensorflow::Node* node() const { return resource.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::Output resource;
};

/// Checks whether a resource handle-based variable has been initialized.
///
/// Arguments:
/// * scope: A Scope object
/// * resource: the input resource handle.
///
/// Returns:
/// * `Output`: a scalar boolean which is true if the variable has been
/// initialized.
class VarIsInitializedOp {
 public:
  VarIsInitializedOp(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   resource);
  operator ::tensorflow::Output() const { return is_initialized; }
  operator ::tensorflow::Input() const { return is_initialized; }
  ::tensorflow::Node* node() const { return is_initialized.node(); }

  ::tensorflow::Output is_initialized;
};

/// Returns the shape of the variable pointed to by `resource`.
///
/// This operation returns a 1-D integer tensor representing the shape of `input`.
///
/// For example:
///
/// ```
/// # 't' is [[[1, 1, 1], [2, 2, 2]], [[3, 3, 3], [4, 4, 4]]]
/// shape(t) ==> [2, 2, 3]
/// ```
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The output tensor.
class VariableShape {
 public:
  /// Optional attribute setters for VariableShape
  struct Attrs {
    /// Defaults to DT_INT32
    TF_MUST_USE_RESULT Attrs OutType(DataType x) {
      Attrs ret = *this;
      ret.out_type_ = x;
      return ret;
    }

    DataType out_type_ = DT_INT32;
  };
  VariableShape(const ::tensorflow::Scope& scope, ::tensorflow::Input input);
  VariableShape(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
              const VariableShape::Attrs& attrs);
  operator ::tensorflow::Output() const { return output; }
  operator ::tensorflow::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  static Attrs OutType(DataType x) {
    return Attrs().OutType(x);
  }

  ::tensorflow::Output output;
};

/// @}

}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_RESOURCE_VARIABLE_OPS_H_
