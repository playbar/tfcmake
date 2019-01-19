// This file is MACHINE GENERATED! Do not edit.


#include "tensorflow/cc/ops/const_op.h"
#include "tensorflow/cc/ops/summary_ops_internal.h"

namespace tensorflow {
namespace ops {
namespace internal {
// NOTE: This namespace has internal TensorFlow details that
// are not part of TensorFlow's public API.

CloseSummaryWriter::CloseSummaryWriter(const ::tensorflow::Scope& scope,
                                       ::tensorflow::Input writer) {
  if (!scope.ok()) return;
  auto _writer = ::tensorflow::ops::AsNodeOut(scope, writer);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("CloseSummaryWriter");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "CloseSummaryWriter")
                     .Input(_writer)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

CreateSummaryDbWriter::CreateSummaryDbWriter(const ::tensorflow::Scope& scope,
                                             ::tensorflow::Input writer,
                                             ::tensorflow::Input db_uri,
                                             ::tensorflow::Input
                                             experiment_name,
                                             ::tensorflow::Input run_name,
                                             ::tensorflow::Input user_name) {
  if (!scope.ok()) return;
  auto _writer = ::tensorflow::ops::AsNodeOut(scope, writer);
  if (!scope.ok()) return;
  auto _db_uri = ::tensorflow::ops::AsNodeOut(scope, db_uri);
  if (!scope.ok()) return;
  auto _experiment_name = ::tensorflow::ops::AsNodeOut(scope, experiment_name);
  if (!scope.ok()) return;
  auto _run_name = ::tensorflow::ops::AsNodeOut(scope, run_name);
  if (!scope.ok()) return;
  auto _user_name = ::tensorflow::ops::AsNodeOut(scope, user_name);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("CreateSummaryDbWriter");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "CreateSummaryDbWriter")
                     .Input(_writer)
                     .Input(_db_uri)
                     .Input(_experiment_name)
                     .Input(_run_name)
                     .Input(_user_name)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

CreateSummaryFileWriter::CreateSummaryFileWriter(const ::tensorflow::Scope&
                                                 scope, ::tensorflow::Input
                                                 writer, ::tensorflow::Input
                                                 logdir, ::tensorflow::Input
                                                 max_queue, ::tensorflow::Input
                                                 flush_millis,
                                                 ::tensorflow::Input
                                                 filename_suffix) {
  if (!scope.ok()) return;
  auto _writer = ::tensorflow::ops::AsNodeOut(scope, writer);
  if (!scope.ok()) return;
  auto _logdir = ::tensorflow::ops::AsNodeOut(scope, logdir);
  if (!scope.ok()) return;
  auto _max_queue = ::tensorflow::ops::AsNodeOut(scope, max_queue);
  if (!scope.ok()) return;
  auto _flush_millis = ::tensorflow::ops::AsNodeOut(scope, flush_millis);
  if (!scope.ok()) return;
  auto _filename_suffix = ::tensorflow::ops::AsNodeOut(scope, filename_suffix);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("CreateSummaryFileWriter");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "CreateSummaryFileWriter")
                     .Input(_writer)
                     .Input(_logdir)
                     .Input(_max_queue)
                     .Input(_flush_millis)
                     .Input(_filename_suffix)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

FlushSummaryWriter::FlushSummaryWriter(const ::tensorflow::Scope& scope,
                                       ::tensorflow::Input writer) {
  if (!scope.ok()) return;
  auto _writer = ::tensorflow::ops::AsNodeOut(scope, writer);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("FlushSummaryWriter");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "FlushSummaryWriter")
                     .Input(_writer)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

ImportEvent::ImportEvent(const ::tensorflow::Scope& scope, ::tensorflow::Input
                         writer, ::tensorflow::Input event) {
  if (!scope.ok()) return;
  auto _writer = ::tensorflow::ops::AsNodeOut(scope, writer);
  if (!scope.ok()) return;
  auto _event = ::tensorflow::ops::AsNodeOut(scope, event);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("ImportEvent");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "ImportEvent")
                     .Input(_writer)
                     .Input(_event)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

SummaryWriter::SummaryWriter(const ::tensorflow::Scope& scope, const
                             SummaryWriter::Attrs& attrs) {
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("SummaryWriter");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "SummaryWriter")
                     .Attr("shared_name", attrs.shared_name_)
                     .Attr("container", attrs.container_)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->writer = Output(ret, 0);
}

SummaryWriter::SummaryWriter(const ::tensorflow::Scope& scope)
  : SummaryWriter(scope, SummaryWriter::Attrs()) {}

WriteAudioSummary::WriteAudioSummary(const ::tensorflow::Scope& scope,
                                     ::tensorflow::Input writer,
                                     ::tensorflow::Input step,
                                     ::tensorflow::Input tag,
                                     ::tensorflow::Input tensor,
                                     ::tensorflow::Input sample_rate, const
                                     WriteAudioSummary::Attrs& attrs) {
  if (!scope.ok()) return;
  auto _writer = ::tensorflow::ops::AsNodeOut(scope, writer);
  if (!scope.ok()) return;
  auto _step = ::tensorflow::ops::AsNodeOut(scope, step);
  if (!scope.ok()) return;
  auto _tag = ::tensorflow::ops::AsNodeOut(scope, tag);
  if (!scope.ok()) return;
  auto _tensor = ::tensorflow::ops::AsNodeOut(scope, tensor);
  if (!scope.ok()) return;
  auto _sample_rate = ::tensorflow::ops::AsNodeOut(scope, sample_rate);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("WriteAudioSummary");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "WriteAudioSummary")
                     .Input(_writer)
                     .Input(_step)
                     .Input(_tag)
                     .Input(_tensor)
                     .Input(_sample_rate)
                     .Attr("max_outputs", attrs.max_outputs_)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

WriteAudioSummary::WriteAudioSummary(const ::tensorflow::Scope& scope,
                                     ::tensorflow::Input writer,
                                     ::tensorflow::Input step,
                                     ::tensorflow::Input tag,
                                     ::tensorflow::Input tensor,
                                     ::tensorflow::Input sample_rate)
  : WriteAudioSummary(scope, writer, step, tag, tensor, sample_rate, WriteAudioSummary::Attrs()) {}

WriteGraphSummary::WriteGraphSummary(const ::tensorflow::Scope& scope,
                                     ::tensorflow::Input writer,
                                     ::tensorflow::Input step,
                                     ::tensorflow::Input tensor) {
  if (!scope.ok()) return;
  auto _writer = ::tensorflow::ops::AsNodeOut(scope, writer);
  if (!scope.ok()) return;
  auto _step = ::tensorflow::ops::AsNodeOut(scope, step);
  if (!scope.ok()) return;
  auto _tensor = ::tensorflow::ops::AsNodeOut(scope, tensor);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("WriteGraphSummary");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "WriteGraphSummary")
                     .Input(_writer)
                     .Input(_step)
                     .Input(_tensor)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

WriteHistogramSummary::WriteHistogramSummary(const ::tensorflow::Scope& scope,
                                             ::tensorflow::Input writer,
                                             ::tensorflow::Input step,
                                             ::tensorflow::Input tag,
                                             ::tensorflow::Input values) {
  if (!scope.ok()) return;
  auto _writer = ::tensorflow::ops::AsNodeOut(scope, writer);
  if (!scope.ok()) return;
  auto _step = ::tensorflow::ops::AsNodeOut(scope, step);
  if (!scope.ok()) return;
  auto _tag = ::tensorflow::ops::AsNodeOut(scope, tag);
  if (!scope.ok()) return;
  auto _values = ::tensorflow::ops::AsNodeOut(scope, values);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("WriteHistogramSummary");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "WriteHistogramSummary")
                     .Input(_writer)
                     .Input(_step)
                     .Input(_tag)
                     .Input(_values)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

WriteImageSummary::WriteImageSummary(const ::tensorflow::Scope& scope,
                                     ::tensorflow::Input writer,
                                     ::tensorflow::Input step,
                                     ::tensorflow::Input tag,
                                     ::tensorflow::Input tensor,
                                     ::tensorflow::Input bad_color, const
                                     WriteImageSummary::Attrs& attrs) {
  if (!scope.ok()) return;
  auto _writer = ::tensorflow::ops::AsNodeOut(scope, writer);
  if (!scope.ok()) return;
  auto _step = ::tensorflow::ops::AsNodeOut(scope, step);
  if (!scope.ok()) return;
  auto _tag = ::tensorflow::ops::AsNodeOut(scope, tag);
  if (!scope.ok()) return;
  auto _tensor = ::tensorflow::ops::AsNodeOut(scope, tensor);
  if (!scope.ok()) return;
  auto _bad_color = ::tensorflow::ops::AsNodeOut(scope, bad_color);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("WriteImageSummary");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "WriteImageSummary")
                     .Input(_writer)
                     .Input(_step)
                     .Input(_tag)
                     .Input(_tensor)
                     .Input(_bad_color)
                     .Attr("max_images", attrs.max_images_)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

WriteImageSummary::WriteImageSummary(const ::tensorflow::Scope& scope,
                                     ::tensorflow::Input writer,
                                     ::tensorflow::Input step,
                                     ::tensorflow::Input tag,
                                     ::tensorflow::Input tensor,
                                     ::tensorflow::Input bad_color)
  : WriteImageSummary(scope, writer, step, tag, tensor, bad_color, WriteImageSummary::Attrs()) {}

WriteScalarSummary::WriteScalarSummary(const ::tensorflow::Scope& scope,
                                       ::tensorflow::Input writer,
                                       ::tensorflow::Input step,
                                       ::tensorflow::Input tag,
                                       ::tensorflow::Input value) {
  if (!scope.ok()) return;
  auto _writer = ::tensorflow::ops::AsNodeOut(scope, writer);
  if (!scope.ok()) return;
  auto _step = ::tensorflow::ops::AsNodeOut(scope, step);
  if (!scope.ok()) return;
  auto _tag = ::tensorflow::ops::AsNodeOut(scope, tag);
  if (!scope.ok()) return;
  auto _value = ::tensorflow::ops::AsNodeOut(scope, value);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("WriteScalarSummary");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "WriteScalarSummary")
                     .Input(_writer)
                     .Input(_step)
                     .Input(_tag)
                     .Input(_value)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

WriteSummary::WriteSummary(const ::tensorflow::Scope& scope,
                           ::tensorflow::Input writer, ::tensorflow::Input
                           step, ::tensorflow::Input tensor,
                           ::tensorflow::Input tag, ::tensorflow::Input
                           summary_metadata) {
  if (!scope.ok()) return;
  auto _writer = ::tensorflow::ops::AsNodeOut(scope, writer);
  if (!scope.ok()) return;
  auto _step = ::tensorflow::ops::AsNodeOut(scope, step);
  if (!scope.ok()) return;
  auto _tensor = ::tensorflow::ops::AsNodeOut(scope, tensor);
  if (!scope.ok()) return;
  auto _tag = ::tensorflow::ops::AsNodeOut(scope, tag);
  if (!scope.ok()) return;
  auto _summary_metadata = ::tensorflow::ops::AsNodeOut(scope, summary_metadata);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("WriteSummary");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "WriteSummary")
                     .Input(_writer)
                     .Input(_step)
                     .Input(_tensor)
                     .Input(_tag)
                     .Input(_summary_metadata)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

}  // namespace internal
}  // namespace ops
}  // namespace tensorflow
