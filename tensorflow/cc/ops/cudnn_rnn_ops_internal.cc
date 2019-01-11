// This file is MACHINE GENERATED! Do not edit.


#include "tensorflow/cc/ops/const_op.h"
#include "/mywork/github/tfcmake/cmake-build-debug/tensorflow/cc/ops/cudnn_rnn_ops_internal.h"

namespace tensorflow {
namespace ops {
namespace internal {
// NOTE: This namespace has internal TensorFlow details that
// are not part of TensorFlow's public API.

CudnnRNNBackpropV2::CudnnRNNBackpropV2(const ::tensorflow::Scope& scope,
                                       ::tensorflow::Input input,
                                       ::tensorflow::Input input_h,
                                       ::tensorflow::Input input_c,
                                       ::tensorflow::Input params,
                                       ::tensorflow::Input output,
                                       ::tensorflow::Input output_h,
                                       ::tensorflow::Input output_c,
                                       ::tensorflow::Input output_backprop,
                                       ::tensorflow::Input output_h_backprop,
                                       ::tensorflow::Input output_c_backprop,
                                       ::tensorflow::Input reserve_space,
                                       ::tensorflow::Input host_reserved, const
                                       CudnnRNNBackpropV2::Attrs& attrs) {
  if (!scope.ok()) return;
  auto _input = ::tensorflow::ops::AsNodeOut(scope, input);
  if (!scope.ok()) return;
  auto _input_h = ::tensorflow::ops::AsNodeOut(scope, input_h);
  if (!scope.ok()) return;
  auto _input_c = ::tensorflow::ops::AsNodeOut(scope, input_c);
  if (!scope.ok()) return;
  auto _params = ::tensorflow::ops::AsNodeOut(scope, params);
  if (!scope.ok()) return;
  auto _output = ::tensorflow::ops::AsNodeOut(scope, output);
  if (!scope.ok()) return;
  auto _output_h = ::tensorflow::ops::AsNodeOut(scope, output_h);
  if (!scope.ok()) return;
  auto _output_c = ::tensorflow::ops::AsNodeOut(scope, output_c);
  if (!scope.ok()) return;
  auto _output_backprop = ::tensorflow::ops::AsNodeOut(scope, output_backprop);
  if (!scope.ok()) return;
  auto _output_h_backprop = ::tensorflow::ops::AsNodeOut(scope, output_h_backprop);
  if (!scope.ok()) return;
  auto _output_c_backprop = ::tensorflow::ops::AsNodeOut(scope, output_c_backprop);
  if (!scope.ok()) return;
  auto _reserve_space = ::tensorflow::ops::AsNodeOut(scope, reserve_space);
  if (!scope.ok()) return;
  auto _host_reserved = ::tensorflow::ops::AsNodeOut(scope, host_reserved);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("CudnnRNNBackpropV2");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "CudnnRNNBackpropV2")
                     .Input(_input)
                     .Input(_input_h)
                     .Input(_input_c)
                     .Input(_params)
                     .Input(_output)
                     .Input(_output_h)
                     .Input(_output_c)
                     .Input(_output_backprop)
                     .Input(_output_h_backprop)
                     .Input(_output_c_backprop)
                     .Input(_reserve_space)
                     .Input(_host_reserved)
                     .Attr("rnn_mode", attrs.rnn_mode_)
                     .Attr("input_mode", attrs.input_mode_)
                     .Attr("direction", attrs.direction_)
                     .Attr("dropout", attrs.dropout_)
                     .Attr("seed", attrs.seed_)
                     .Attr("seed2", attrs.seed2_)
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

  this->input_backprop = Output(ret, _outputs_range["input_backprop"].first);
  this->input_h_backprop = Output(ret, _outputs_range["input_h_backprop"].first);
  this->input_c_backprop = Output(ret, _outputs_range["input_c_backprop"].first);
  this->params_backprop = Output(ret, _outputs_range["params_backprop"].first);
}

CudnnRNNBackpropV2::CudnnRNNBackpropV2(const ::tensorflow::Scope& scope,
                                       ::tensorflow::Input input,
                                       ::tensorflow::Input input_h,
                                       ::tensorflow::Input input_c,
                                       ::tensorflow::Input params,
                                       ::tensorflow::Input output,
                                       ::tensorflow::Input output_h,
                                       ::tensorflow::Input output_c,
                                       ::tensorflow::Input output_backprop,
                                       ::tensorflow::Input output_h_backprop,
                                       ::tensorflow::Input output_c_backprop,
                                       ::tensorflow::Input reserve_space,
                                       ::tensorflow::Input host_reserved)
  : CudnnRNNBackpropV2(scope, input, input_h, input_c, params, output, output_h, output_c, output_backprop, output_h_backprop, output_c_backprop, reserve_space, host_reserved, CudnnRNNBackpropV2::Attrs()) {}

CudnnRNNV2::CudnnRNNV2(const ::tensorflow::Scope& scope, ::tensorflow::Input
                       input, ::tensorflow::Input input_h, ::tensorflow::Input
                       input_c, ::tensorflow::Input params, const
                       CudnnRNNV2::Attrs& attrs) {
  if (!scope.ok()) return;
  auto _input = ::tensorflow::ops::AsNodeOut(scope, input);
  if (!scope.ok()) return;
  auto _input_h = ::tensorflow::ops::AsNodeOut(scope, input_h);
  if (!scope.ok()) return;
  auto _input_c = ::tensorflow::ops::AsNodeOut(scope, input_c);
  if (!scope.ok()) return;
  auto _params = ::tensorflow::ops::AsNodeOut(scope, params);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("CudnnRNNV2");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "CudnnRNNV2")
                     .Input(_input)
                     .Input(_input_h)
                     .Input(_input_c)
                     .Input(_params)
                     .Attr("rnn_mode", attrs.rnn_mode_)
                     .Attr("input_mode", attrs.input_mode_)
                     .Attr("direction", attrs.direction_)
                     .Attr("dropout", attrs.dropout_)
                     .Attr("seed", attrs.seed_)
                     .Attr("seed2", attrs.seed2_)
                     .Attr("is_training", attrs.is_training_)
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

  this->output = Output(ret, _outputs_range["output"].first);
  this->output_h = Output(ret, _outputs_range["output_h"].first);
  this->output_c = Output(ret, _outputs_range["output_c"].first);
  this->reserve_space = Output(ret, _outputs_range["reserve_space"].first);
  this->host_reserved = Output(ret, _outputs_range["host_reserved"].first);
}

CudnnRNNV2::CudnnRNNV2(const ::tensorflow::Scope& scope, ::tensorflow::Input
                       input, ::tensorflow::Input input_h, ::tensorflow::Input
                       input_c, ::tensorflow::Input params)
  : CudnnRNNV2(scope, input, input_h, input_c, params, CudnnRNNV2::Attrs()) {}

}  // namespace internal
}  // namespace ops
}  // namespace tensorflow
