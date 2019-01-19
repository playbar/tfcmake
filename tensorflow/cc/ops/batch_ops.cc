// This file is MACHINE GENERATED! Do not edit.


#include "tensorflow/cc/ops/const_op.h"
#include "tensorflow/cc/ops/batch_ops.h"

namespace tensorflow {
namespace ops {

Batch::Batch(const ::tensorflow::Scope& scope, ::tensorflow::InputList
             in_tensors, int64 num_batch_threads, int64 max_batch_size, int64
             batch_timeout_micros, int64 grad_timeout_micros, const
             Batch::Attrs& attrs) {
  if (!scope.ok()) return;
  auto _in_tensors = ::tensorflow::ops::AsNodeOutList(scope, in_tensors);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("Batch");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "Batch")
                     .Input(_in_tensors)
                     .Attr("num_batch_threads", num_batch_threads)
                     .Attr("max_batch_size", max_batch_size)
                     .Attr("max_enqueued_batches", attrs.max_enqueued_batches_)
                     .Attr("batch_timeout_micros", batch_timeout_micros)
                     .Attr("allowed_batch_sizes", attrs.allowed_batch_sizes_)
                     .Attr("grad_timeout_micros", grad_timeout_micros)
                     .Attr("container", attrs.container_)
                     .Attr("shared_name", attrs.shared_name_)
                     .Attr("batching_queue", attrs.batching_queue_)
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

  for (int32 i = _outputs_range["batched_tensors"].first; i < _outputs_range["batched_tensors"].second; ++i)
    this->batched_tensors.push_back(Output(ret, i));
  this->batch_index = Output(ret, _outputs_range["batch_index"].first);
  this->id = Output(ret, _outputs_range["id"].first);
}

Batch::Batch(const ::tensorflow::Scope& scope, ::tensorflow::InputList
             in_tensors, int64 num_batch_threads, int64 max_batch_size, int64
             batch_timeout_micros, int64 grad_timeout_micros)
  : Batch(scope, in_tensors, num_batch_threads, max_batch_size, batch_timeout_micros, grad_timeout_micros, Batch::Attrs()) {}

Unbatch::Unbatch(const ::tensorflow::Scope& scope, ::tensorflow::Input
                 batched_tensor, ::tensorflow::Input batch_index,
                 ::tensorflow::Input id, int64 timeout_micros, const
                 Unbatch::Attrs& attrs) {
  if (!scope.ok()) return;
  auto _batched_tensor = ::tensorflow::ops::AsNodeOut(scope, batched_tensor);
  if (!scope.ok()) return;
  auto _batch_index = ::tensorflow::ops::AsNodeOut(scope, batch_index);
  if (!scope.ok()) return;
  auto _id = ::tensorflow::ops::AsNodeOut(scope, id);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("Unbatch");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "Unbatch")
                     .Input(_batched_tensor)
                     .Input(_batch_index)
                     .Input(_id)
                     .Attr("timeout_micros", timeout_micros)
                     .Attr("container", attrs.container_)
                     .Attr("shared_name", attrs.shared_name_)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->unbatched_tensor = Output(ret, 0);
}

Unbatch::Unbatch(const ::tensorflow::Scope& scope, ::tensorflow::Input
                 batched_tensor, ::tensorflow::Input batch_index,
                 ::tensorflow::Input id, int64 timeout_micros)
  : Unbatch(scope, batched_tensor, batch_index, id, timeout_micros, Unbatch::Attrs()) {}

UnbatchGrad::UnbatchGrad(const ::tensorflow::Scope& scope, ::tensorflow::Input
                         original_input, ::tensorflow::Input batch_index,
                         ::tensorflow::Input grad, ::tensorflow::Input id,
                         const UnbatchGrad::Attrs& attrs) {
  if (!scope.ok()) return;
  auto _original_input = ::tensorflow::ops::AsNodeOut(scope, original_input);
  if (!scope.ok()) return;
  auto _batch_index = ::tensorflow::ops::AsNodeOut(scope, batch_index);
  if (!scope.ok()) return;
  auto _grad = ::tensorflow::ops::AsNodeOut(scope, grad);
  if (!scope.ok()) return;
  auto _id = ::tensorflow::ops::AsNodeOut(scope, id);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("UnbatchGrad");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "UnbatchGrad")
                     .Input(_original_input)
                     .Input(_batch_index)
                     .Input(_grad)
                     .Input(_id)
                     .Attr("container", attrs.container_)
                     .Attr("shared_name", attrs.shared_name_)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->batched_grad = Output(ret, 0);
}

UnbatchGrad::UnbatchGrad(const ::tensorflow::Scope& scope, ::tensorflow::Input
                         original_input, ::tensorflow::Input batch_index,
                         ::tensorflow::Input grad, ::tensorflow::Input id)
  : UnbatchGrad(scope, original_input, batch_index, grad, id, UnbatchGrad::Attrs()) {}

/// @}

}  // namespace ops
}  // namespace tensorflow
