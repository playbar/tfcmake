// This file is MACHINE GENERATED! Do not edit.


#include "tensorflow/cc/ops/const_op.h"
#include "/mywork/github/tfcmake/cmake-build-debug/tensorflow/cc/ops/list_ops.h"

namespace tensorflow {
namespace ops {

EmptyTensorList::EmptyTensorList(const ::tensorflow::Scope& scope,
                                 ::tensorflow::Input element_shape, DataType
                                 element_dtype) {
  if (!scope.ok()) return;
  auto _element_shape = ::tensorflow::ops::AsNodeOut(scope, element_shape);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("EmptyTensorList");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "EmptyTensorList")
                     .Input(_element_shape)
                     .Attr("element_dtype", element_dtype)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->handle = Output(ret, 0);
}

TensorListConcatLists::TensorListConcatLists(const ::tensorflow::Scope& scope,
                                             ::tensorflow::Input input_a,
                                             ::tensorflow::Input input_b,
                                             DataType element_dtype) {
  if (!scope.ok()) return;
  auto _input_a = ::tensorflow::ops::AsNodeOut(scope, input_a);
  if (!scope.ok()) return;
  auto _input_b = ::tensorflow::ops::AsNodeOut(scope, input_b);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("TensorListConcatLists");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "TensorListConcatLists")
                     .Input(_input_a)
                     .Input(_input_b)
                     .Attr("element_dtype", element_dtype)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->output = Output(ret, 0);
}

TensorListElementShape::TensorListElementShape(const ::tensorflow::Scope&
                                               scope, ::tensorflow::Input
                                               input_handle, DataType
                                               shape_type) {
  if (!scope.ok()) return;
  auto _input_handle = ::tensorflow::ops::AsNodeOut(scope, input_handle);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("TensorListElementShape");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "TensorListElementShape")
                     .Input(_input_handle)
                     .Attr("shape_type", shape_type)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->element_shape = Output(ret, 0);
}

TensorListFromTensor::TensorListFromTensor(const ::tensorflow::Scope& scope,
                                           ::tensorflow::Input tensor,
                                           ::tensorflow::Input element_shape) {
  if (!scope.ok()) return;
  auto _tensor = ::tensorflow::ops::AsNodeOut(scope, tensor);
  if (!scope.ok()) return;
  auto _element_shape = ::tensorflow::ops::AsNodeOut(scope, element_shape);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("TensorListFromTensor");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "TensorListFromTensor")
                     .Input(_tensor)
                     .Input(_element_shape)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->output_handle = Output(ret, 0);
}

TensorListGetItem::TensorListGetItem(const ::tensorflow::Scope& scope,
                                     ::tensorflow::Input input_handle,
                                     ::tensorflow::Input index, DataType
                                     element_dtype) {
  if (!scope.ok()) return;
  auto _input_handle = ::tensorflow::ops::AsNodeOut(scope, input_handle);
  if (!scope.ok()) return;
  auto _index = ::tensorflow::ops::AsNodeOut(scope, index);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("TensorListGetItem");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "TensorListGetItem")
                     .Input(_input_handle)
                     .Input(_index)
                     .Attr("element_dtype", element_dtype)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->item = Output(ret, 0);
}

TensorListLength::TensorListLength(const ::tensorflow::Scope& scope,
                                   ::tensorflow::Input input_handle) {
  if (!scope.ok()) return;
  auto _input_handle = ::tensorflow::ops::AsNodeOut(scope, input_handle);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("TensorListLength");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "TensorListLength")
                     .Input(_input_handle)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->length = Output(ret, 0);
}

TensorListPopBack::TensorListPopBack(const ::tensorflow::Scope& scope,
                                     ::tensorflow::Input input_handle, DataType
                                     element_dtype) {
  if (!scope.ok()) return;
  auto _input_handle = ::tensorflow::ops::AsNodeOut(scope, input_handle);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("TensorListPopBack");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "TensorListPopBack")
                     .Input(_input_handle)
                     .Attr("element_dtype", element_dtype)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  ::tensorflow::NameRangeMap _outputs_range;
  ::tensorflow::Status _status_ = ::tensorflow::NameRangesForNode(*ret, ret->op_def(), nullptr, &_outputs_range);
  if (!_status_.ok()) {
    scope.UpdateStatus(_status_);
    return;
  }

  this->output_handle = Output(ret, _outputs_range["output_handle"].first);
  this->tensor = Output(ret, _outputs_range["tensor"].first);
}

TensorListPushBack::TensorListPushBack(const ::tensorflow::Scope& scope,
                                       ::tensorflow::Input input_handle,
                                       ::tensorflow::Input tensor) {
  if (!scope.ok()) return;
  auto _input_handle = ::tensorflow::ops::AsNodeOut(scope, input_handle);
  if (!scope.ok()) return;
  auto _tensor = ::tensorflow::ops::AsNodeOut(scope, tensor);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("TensorListPushBack");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "TensorListPushBack")
                     .Input(_input_handle)
                     .Input(_tensor)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->output_handle = Output(ret, 0);
}

TensorListPushBackBatch::TensorListPushBackBatch(const ::tensorflow::Scope&
                                                 scope, ::tensorflow::Input
                                                 input_handles,
                                                 ::tensorflow::Input tensor) {
  if (!scope.ok()) return;
  auto _input_handles = ::tensorflow::ops::AsNodeOut(scope, input_handles);
  if (!scope.ok()) return;
  auto _tensor = ::tensorflow::ops::AsNodeOut(scope, tensor);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("TensorListPushBackBatch");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "TensorListPushBackBatch")
                     .Input(_input_handles)
                     .Input(_tensor)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->output_handles = Output(ret, 0);
}

TensorListReserve::TensorListReserve(const ::tensorflow::Scope& scope,
                                     ::tensorflow::Input element_shape,
                                     ::tensorflow::Input num_elements, DataType
                                     element_dtype) {
  if (!scope.ok()) return;
  auto _element_shape = ::tensorflow::ops::AsNodeOut(scope, element_shape);
  if (!scope.ok()) return;
  auto _num_elements = ::tensorflow::ops::AsNodeOut(scope, num_elements);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("TensorListReserve");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "TensorListReserve")
                     .Input(_element_shape)
                     .Input(_num_elements)
                     .Attr("element_dtype", element_dtype)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->handle = Output(ret, 0);
}

TensorListSetItem::TensorListSetItem(const ::tensorflow::Scope& scope,
                                     ::tensorflow::Input input_handle,
                                     ::tensorflow::Input index,
                                     ::tensorflow::Input item) {
  if (!scope.ok()) return;
  auto _input_handle = ::tensorflow::ops::AsNodeOut(scope, input_handle);
  if (!scope.ok()) return;
  auto _index = ::tensorflow::ops::AsNodeOut(scope, index);
  if (!scope.ok()) return;
  auto _item = ::tensorflow::ops::AsNodeOut(scope, item);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("TensorListSetItem");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "TensorListSetItem")
                     .Input(_input_handle)
                     .Input(_index)
                     .Input(_item)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->output_handle = Output(ret, 0);
}

TensorListStack::TensorListStack(const ::tensorflow::Scope& scope,
                                 ::tensorflow::Input input_handle, DataType
                                 element_dtype, const TensorListStack::Attrs&
                                 attrs) {
  if (!scope.ok()) return;
  auto _input_handle = ::tensorflow::ops::AsNodeOut(scope, input_handle);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("TensorListStack");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "TensorListStack")
                     .Input(_input_handle)
                     .Attr("element_dtype", element_dtype)
                     .Attr("num_elements", attrs.num_elements_)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->tensor = Output(ret, 0);
}

TensorListStack::TensorListStack(const ::tensorflow::Scope& scope,
                                 ::tensorflow::Input input_handle, DataType
                                 element_dtype)
  : TensorListStack(scope, input_handle, element_dtype, TensorListStack::Attrs()) {}

/// @}

}  // namespace ops
}  // namespace tensorflow
