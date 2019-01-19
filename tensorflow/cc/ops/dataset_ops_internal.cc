// This file is MACHINE GENERATED! Do not edit.


#include "tensorflow/cc/ops/const_op.h"
#include "tensorflow/cc/ops/dataset_ops_internal.h"

namespace tensorflow {
namespace ops {
namespace internal {
// NOTE: This namespace has internal TensorFlow details that
// are not part of TensorFlow's public API.

DatasetToTFRecord::DatasetToTFRecord(const ::tensorflow::Scope& scope,
                                     ::tensorflow::Input input_dataset,
                                     ::tensorflow::Input filename,
                                     ::tensorflow::Input compression_type) {
  if (!scope.ok()) return;
  auto _input_dataset = ::tensorflow::ops::AsNodeOut(scope, input_dataset);
  if (!scope.ok()) return;
  auto _filename = ::tensorflow::ops::AsNodeOut(scope, filename);
  if (!scope.ok()) return;
  auto _compression_type = ::tensorflow::ops::AsNodeOut(scope, compression_type);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("DatasetToTFRecord");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "DatasetToTFRecord")
                     .Input(_input_dataset)
                     .Input(_filename)
                     .Input(_compression_type)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

GroupByReducerDataset::GroupByReducerDataset(const ::tensorflow::Scope& scope,
                                             ::tensorflow::Input input_dataset,
                                             ::tensorflow::InputList
                                             key_func_other_arguments,
                                             ::tensorflow::InputList
                                             init_func_other_arguments,
                                             ::tensorflow::InputList
                                             reduce_func_other_arguments,
                                             ::tensorflow::InputList
                                             finalize_func_other_arguments,
                                             const NameAttrList& key_func,
                                             const NameAttrList& init_func,
                                             const NameAttrList& reduce_func,
                                             const NameAttrList& finalize_func,
                                             const DataTypeSlice& output_types,
                                             const
                                             gtl::ArraySlice<PartialTensorShape>&
                                             output_shapes) {
  if (!scope.ok()) return;
  auto _input_dataset = ::tensorflow::ops::AsNodeOut(scope, input_dataset);
  if (!scope.ok()) return;
  auto _key_func_other_arguments = ::tensorflow::ops::AsNodeOutList(scope, key_func_other_arguments);
  if (!scope.ok()) return;
  auto _init_func_other_arguments = ::tensorflow::ops::AsNodeOutList(scope, init_func_other_arguments);
  if (!scope.ok()) return;
  auto _reduce_func_other_arguments = ::tensorflow::ops::AsNodeOutList(scope, reduce_func_other_arguments);
  if (!scope.ok()) return;
  auto _finalize_func_other_arguments = ::tensorflow::ops::AsNodeOutList(scope, finalize_func_other_arguments);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("GroupByReducerDataset");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "GroupByReducerDataset")
                     .Input(_input_dataset)
                     .Input(_key_func_other_arguments)
                     .Input(_init_func_other_arguments)
                     .Input(_reduce_func_other_arguments)
                     .Input(_finalize_func_other_arguments)
                     .Attr("key_func", key_func)
                     .Attr("init_func", init_func)
                     .Attr("reduce_func", reduce_func)
                     .Attr("finalize_func", finalize_func)
                     .Attr("output_types", output_types)
                     .Attr("output_shapes", output_shapes)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->handle = Output(ret, 0);
}

MapAndBatchDataset::MapAndBatchDataset(const ::tensorflow::Scope& scope,
                                       ::tensorflow::Input input_dataset,
                                       ::tensorflow::InputList other_arguments,
                                       ::tensorflow::Input batch_size,
                                       ::tensorflow::Input
                                       num_parallel_batches,
                                       ::tensorflow::Input drop_remainder,
                                       const NameAttrList& f, const
                                       DataTypeSlice& output_types, const
                                       gtl::ArraySlice<PartialTensorShape>&
                                       output_shapes) {
  if (!scope.ok()) return;
  auto _input_dataset = ::tensorflow::ops::AsNodeOut(scope, input_dataset);
  if (!scope.ok()) return;
  auto _other_arguments = ::tensorflow::ops::AsNodeOutList(scope, other_arguments);
  if (!scope.ok()) return;
  auto _batch_size = ::tensorflow::ops::AsNodeOut(scope, batch_size);
  if (!scope.ok()) return;
  auto _num_parallel_batches = ::tensorflow::ops::AsNodeOut(scope, num_parallel_batches);
  if (!scope.ok()) return;
  auto _drop_remainder = ::tensorflow::ops::AsNodeOut(scope, drop_remainder);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("MapAndBatchDataset");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "MapAndBatchDataset")
                     .Input(_input_dataset)
                     .Input(_other_arguments)
                     .Input(_batch_size)
                     .Input(_num_parallel_batches)
                     .Input(_drop_remainder)
                     .Attr("f", f)
                     .Attr("output_types", output_types)
                     .Attr("output_shapes", output_shapes)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->handle = Output(ret, 0);
}

MapAndBatchDatasetV2::MapAndBatchDatasetV2(const ::tensorflow::Scope& scope,
                                           ::tensorflow::Input input_dataset,
                                           ::tensorflow::InputList
                                           other_arguments, ::tensorflow::Input
                                           batch_size, ::tensorflow::Input
                                           num_parallel_calls,
                                           ::tensorflow::Input drop_remainder,
                                           const NameAttrList& f, const
                                           DataTypeSlice& output_types, const
                                           gtl::ArraySlice<PartialTensorShape>&
                                           output_shapes) {
  if (!scope.ok()) return;
  auto _input_dataset = ::tensorflow::ops::AsNodeOut(scope, input_dataset);
  if (!scope.ok()) return;
  auto _other_arguments = ::tensorflow::ops::AsNodeOutList(scope, other_arguments);
  if (!scope.ok()) return;
  auto _batch_size = ::tensorflow::ops::AsNodeOut(scope, batch_size);
  if (!scope.ok()) return;
  auto _num_parallel_calls = ::tensorflow::ops::AsNodeOut(scope, num_parallel_calls);
  if (!scope.ok()) return;
  auto _drop_remainder = ::tensorflow::ops::AsNodeOut(scope, drop_remainder);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("MapAndBatchDatasetV2");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "MapAndBatchDatasetV2")
                     .Input(_input_dataset)
                     .Input(_other_arguments)
                     .Input(_batch_size)
                     .Input(_num_parallel_calls)
                     .Input(_drop_remainder)
                     .Attr("f", f)
                     .Attr("output_types", output_types)
                     .Attr("output_shapes", output_shapes)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->handle = Output(ret, 0);
}

}  // namespace internal
}  // namespace ops
}  // namespace tensorflow
