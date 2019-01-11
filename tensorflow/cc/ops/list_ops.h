// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_LIST_OPS_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_LIST_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

/// @defgroup list_ops List Ops
/// @{

/// Creates and returns an empty tensor list.
///
/// All list elements must be tensors of dtype element_dtype and shape compatible
/// with element_shape.
///
/// handle: an empty tensor list.
/// element_dtype: the type of elements in the list.
/// element_shape: a shape compatible with that of elements in the list.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The handle tensor.
class EmptyTensorList {
 public:
  EmptyTensorList(const ::tensorflow::Scope& scope, ::tensorflow::Input
                element_shape, DataType element_dtype);
  operator ::tensorflow::Output() const { return handle; }
  operator ::tensorflow::Input() const { return handle; }
  ::tensorflow::Node* node() const { return handle.node(); }

  ::tensorflow::Output handle;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The output tensor.
class TensorListConcatLists {
 public:
  TensorListConcatLists(const ::tensorflow::Scope& scope, ::tensorflow::Input
                      input_a, ::tensorflow::Input input_b, DataType
                      element_dtype);
  operator ::tensorflow::Output() const { return output; }
  operator ::tensorflow::Input() const { return output; }
  ::tensorflow::Node* node() const { return output.node(); }

  ::tensorflow::Output output;
};

/// The shape of the elements of the given list, as a tensor.
///
///   input_handle: the list
///   element_shape: the shape of elements of the list
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The element_shape tensor.
class TensorListElementShape {
 public:
  TensorListElementShape(const ::tensorflow::Scope& scope, ::tensorflow::Input
                       input_handle, DataType shape_type);
  operator ::tensorflow::Output() const { return element_shape; }
  operator ::tensorflow::Input() const { return element_shape; }
  ::tensorflow::Node* node() const { return element_shape.node(); }

  ::tensorflow::Output element_shape;
};

/// Creates a TensorList which, when stacked, has the value of `tensor`.
///
/// Each tensor in the result list corresponds to one row of the input tensor.
///
/// tensor: The input tensor.
/// output_handle: The list.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The output_handle tensor.
class TensorListFromTensor {
 public:
  TensorListFromTensor(const ::tensorflow::Scope& scope, ::tensorflow::Input
                     tensor, ::tensorflow::Input element_shape);
  operator ::tensorflow::Output() const { return output_handle; }
  operator ::tensorflow::Input() const { return output_handle; }
  ::tensorflow::Node* node() const { return output_handle.node(); }

  ::tensorflow::Output output_handle;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The item tensor.
class TensorListGetItem {
 public:
  TensorListGetItem(const ::tensorflow::Scope& scope, ::tensorflow::Input
                  input_handle, ::tensorflow::Input index, DataType
                  element_dtype);
  operator ::tensorflow::Output() const { return item; }
  operator ::tensorflow::Input() const { return item; }
  ::tensorflow::Node* node() const { return item.node(); }

  ::tensorflow::Output item;
};

/// Returns the number of tensors in the input tensor list.
///
/// input_handle: the input list
/// length: the number of tensors in the list
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The length tensor.
class TensorListLength {
 public:
  TensorListLength(const ::tensorflow::Scope& scope, ::tensorflow::Input
                 input_handle);
  operator ::tensorflow::Output() const { return length; }
  operator ::tensorflow::Input() const { return length; }
  ::tensorflow::Node* node() const { return length.node(); }

  ::tensorflow::Output length;
};

/// Returns the last element of the input list as well as a list with all but that element.
///
/// Fails if the list is empty.
///
/// input_handle: the input list
/// tensor: the withdrawn last element of the list
/// element_dtype: the type of elements in the list
/// element_shape: the shape of the output tensor
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output` output_handle
/// * `Output` tensor
class TensorListPopBack {
 public:
  TensorListPopBack(const ::tensorflow::Scope& scope, ::tensorflow::Input
                  input_handle, DataType element_dtype);

  ::tensorflow::Output output_handle;
  ::tensorflow::Output tensor;
};

/// Returns a list list which has the passed-in `Tensor` as last element and the other elements of the given list in `input_handle`.
///
/// tensor: The tensor to put on the list.
/// input_handle: The old list.
/// output_handle: A list with the elements of the old list followed by tensor.
/// element_dtype: the type of elements in the list.
/// element_shape: a shape compatible with that of elements in the list.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The output_handle tensor.
class TensorListPushBack {
 public:
  TensorListPushBack(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   input_handle, ::tensorflow::Input tensor);
  operator ::tensorflow::Output() const { return output_handle; }
  operator ::tensorflow::Input() const { return output_handle; }
  ::tensorflow::Node* node() const { return output_handle.node(); }

  ::tensorflow::Output output_handle;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The output_handles tensor.
class TensorListPushBackBatch {
 public:
  TensorListPushBackBatch(const ::tensorflow::Scope& scope, ::tensorflow::Input
                        input_handles, ::tensorflow::Input tensor);
  operator ::tensorflow::Output() const { return output_handles; }
  operator ::tensorflow::Input() const { return output_handles; }
  ::tensorflow::Node* node() const { return output_handles.node(); }

  ::tensorflow::Output output_handles;
};

/// List of the given size with empty elements.
///
/// element_shape: the shape of the future elements of the list
/// num_elements: the number of elements to reserve
/// handle: the output list
/// element_dtype: the desired type of elements in the list.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The handle tensor.
class TensorListReserve {
 public:
  TensorListReserve(const ::tensorflow::Scope& scope, ::tensorflow::Input
                  element_shape, ::tensorflow::Input num_elements, DataType
                  element_dtype);
  operator ::tensorflow::Output() const { return handle; }
  operator ::tensorflow::Input() const { return handle; }
  ::tensorflow::Node* node() const { return handle.node(); }

  ::tensorflow::Output handle;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The output_handle tensor.
class TensorListSetItem {
 public:
  TensorListSetItem(const ::tensorflow::Scope& scope, ::tensorflow::Input
                  input_handle, ::tensorflow::Input index, ::tensorflow::Input
                  item);
  operator ::tensorflow::Output() const { return output_handle; }
  operator ::tensorflow::Input() const { return output_handle; }
  ::tensorflow::Node* node() const { return output_handle.node(); }

  ::tensorflow::Output output_handle;
};

/// Stacks all tensors in the list.
///
/// Requires that all tensors have the same shape.
///
/// input_handle: the input list
/// tensor: the gathered result
/// num_elements: optional. If not -1, the number of elements in the list.
///
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The tensor tensor.
class TensorListStack {
 public:
  /// Optional attribute setters for TensorListStack
  struct Attrs {
    /// Defaults to -1
    TF_MUST_USE_RESULT Attrs NumElements(int64 x) {
      Attrs ret = *this;
      ret.num_elements_ = x;
      return ret;
    }

    int64 num_elements_ = -1;
  };
  TensorListStack(const ::tensorflow::Scope& scope, ::tensorflow::Input
                input_handle, DataType element_dtype);
  TensorListStack(const ::tensorflow::Scope& scope, ::tensorflow::Input
                input_handle, DataType element_dtype, const
                TensorListStack::Attrs& attrs);
  operator ::tensorflow::Output() const { return tensor; }
  operator ::tensorflow::Input() const { return tensor; }
  ::tensorflow::Node* node() const { return tensor.node(); }

  static Attrs NumElements(int64 x) {
    return Attrs().NumElements(x);
  }

  ::tensorflow::Output tensor;
};

/// @}

}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_LIST_OPS_H_
