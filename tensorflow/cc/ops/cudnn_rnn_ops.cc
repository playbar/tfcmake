// This file is MACHINE GENERATED! Do not edit.


#include "tensorflow/cc/ops/const_op.h"
#include "tensorflow/cc/ops/cudnn_rnn_ops.h"

namespace tensorflow {
namespace ops {

CudnnRNN::CudnnRNN(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
                   ::tensorflow::Input input_h, ::tensorflow::Input input_c,
                   ::tensorflow::Input params, const CudnnRNN::Attrs& attrs) {
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
  const auto unique_name = scope.GetUniqueNameForOp("CudnnRNN");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "CudnnRNN")
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
}

CudnnRNN::CudnnRNN(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
                   ::tensorflow::Input input_h, ::tensorflow::Input input_c,
                   ::tensorflow::Input params)
  : CudnnRNN(scope, input, input_h, input_c, params, CudnnRNN::Attrs()) {}

CudnnRNNBackprop::CudnnRNNBackprop(const ::tensorflow::Scope& scope,
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
                                   ::tensorflow::Input reserve_space, const
                                   CudnnRNNBackprop::Attrs& attrs) {
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
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("CudnnRNNBackprop");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "CudnnRNNBackprop")
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

CudnnRNNBackprop::CudnnRNNBackprop(const ::tensorflow::Scope& scope,
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
                                   ::tensorflow::Input reserve_space)
  : CudnnRNNBackprop(scope, input, input_h, input_c, params, output, output_h, output_c, output_backprop, output_h_backprop, output_c_backprop, reserve_space, CudnnRNNBackprop::Attrs()) {}

CudnnRNNCanonicalToParams::CudnnRNNCanonicalToParams(const ::tensorflow::Scope&
                                                     scope, ::tensorflow::Input
                                                     num_layers,
                                                     ::tensorflow::Input
                                                     num_units,
                                                     ::tensorflow::Input
                                                     input_size,
                                                     ::tensorflow::InputList
                                                     weights,
                                                     ::tensorflow::InputList
                                                     biases, const
                                                     CudnnRNNCanonicalToParams::Attrs&
                                                     attrs) {
  if (!scope.ok()) return;
  auto _num_layers = ::tensorflow::ops::AsNodeOut(scope, num_layers);
  if (!scope.ok()) return;
  auto _num_units = ::tensorflow::ops::AsNodeOut(scope, num_units);
  if (!scope.ok()) return;
  auto _input_size = ::tensorflow::ops::AsNodeOut(scope, input_size);
  if (!scope.ok()) return;
  auto _weights = ::tensorflow::ops::AsNodeOutList(scope, weights);
  if (!scope.ok()) return;
  auto _biases = ::tensorflow::ops::AsNodeOutList(scope, biases);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("CudnnRNNCanonicalToParams");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "CudnnRNNCanonicalToParams")
                     .Input(_num_layers)
                     .Input(_num_units)
                     .Input(_input_size)
                     .Input(_weights)
                     .Input(_biases)
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
  this->params = Output(ret, 0);
}

CudnnRNNCanonicalToParams::CudnnRNNCanonicalToParams(const ::tensorflow::Scope&
                                                     scope, ::tensorflow::Input
                                                     num_layers,
                                                     ::tensorflow::Input
                                                     num_units,
                                                     ::tensorflow::Input
                                                     input_size,
                                                     ::tensorflow::InputList
                                                     weights,
                                                     ::tensorflow::InputList
                                                     biases)
  : CudnnRNNCanonicalToParams(scope, num_layers, num_units, input_size, weights, biases, CudnnRNNCanonicalToParams::Attrs()) {}

CudnnRNNParamsSize::CudnnRNNParamsSize(const ::tensorflow::Scope& scope,
                                       ::tensorflow::Input num_layers,
                                       ::tensorflow::Input num_units,
                                       ::tensorflow::Input input_size, DataType
                                       T, DataType S, const
                                       CudnnRNNParamsSize::Attrs& attrs) {
  if (!scope.ok()) return;
  auto _num_layers = ::tensorflow::ops::AsNodeOut(scope, num_layers);
  if (!scope.ok()) return;
  auto _num_units = ::tensorflow::ops::AsNodeOut(scope, num_units);
  if (!scope.ok()) return;
  auto _input_size = ::tensorflow::ops::AsNodeOut(scope, input_size);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("CudnnRNNParamsSize");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "CudnnRNNParamsSize")
                     .Input(_num_layers)
                     .Input(_num_units)
                     .Input(_input_size)
                     .Attr("T", T)
                     .Attr("S", S)
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
  this->params_size = Output(ret, 0);
}

CudnnRNNParamsSize::CudnnRNNParamsSize(const ::tensorflow::Scope& scope,
                                       ::tensorflow::Input num_layers,
                                       ::tensorflow::Input num_units,
                                       ::tensorflow::Input input_size, DataType
                                       T, DataType S)
  : CudnnRNNParamsSize(scope, num_layers, num_units, input_size, T, S, CudnnRNNParamsSize::Attrs()) {}

CudnnRNNParamsToCanonical::CudnnRNNParamsToCanonical(const ::tensorflow::Scope&
                                                     scope, ::tensorflow::Input
                                                     num_layers,
                                                     ::tensorflow::Input
                                                     num_units,
                                                     ::tensorflow::Input
                                                     input_size,
                                                     ::tensorflow::Input
                                                     params, int64 num_params,
                                                     const
                                                     CudnnRNNParamsToCanonical::Attrs&
                                                     attrs) {
  if (!scope.ok()) return;
  auto _num_layers = ::tensorflow::ops::AsNodeOut(scope, num_layers);
  if (!scope.ok()) return;
  auto _num_units = ::tensorflow::ops::AsNodeOut(scope, num_units);
  if (!scope.ok()) return;
  auto _input_size = ::tensorflow::ops::AsNodeOut(scope, input_size);
  if (!scope.ok()) return;
  auto _params = ::tensorflow::ops::AsNodeOut(scope, params);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("CudnnRNNParamsToCanonical");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "CudnnRNNParamsToCanonical")
                     .Input(_num_layers)
                     .Input(_num_units)
                     .Input(_input_size)
                     .Input(_params)
                     .Attr("num_params", num_params)
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

  for (int32 i = _outputs_range["weights"].first; i < _outputs_range["weights"].second; ++i)
    this->weights.push_back(Output(ret, i));
  for (int32 i = _outputs_range["biases"].first; i < _outputs_range["biases"].second; ++i)
    this->biases.push_back(Output(ret, i));
}

CudnnRNNParamsToCanonical::CudnnRNNParamsToCanonical(const ::tensorflow::Scope&
                                                     scope, ::tensorflow::Input
                                                     num_layers,
                                                     ::tensorflow::Input
                                                     num_units,
                                                     ::tensorflow::Input
                                                     input_size,
                                                     ::tensorflow::Input
                                                     params, int64 num_params)
  : CudnnRNNParamsToCanonical(scope, num_layers, num_units, input_size, params, num_params, CudnnRNNParamsToCanonical::Attrs()) {}

/// @}

}  // namespace ops
}  // namespace tensorflow
