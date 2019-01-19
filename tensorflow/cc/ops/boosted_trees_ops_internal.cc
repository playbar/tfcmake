// This file is MACHINE GENERATED! Do not edit.


#include "tensorflow/cc/ops/const_op.h"
#include "tensorflow/cc/ops/boosted_trees_ops_internal.h"

namespace tensorflow {
namespace ops {
namespace internal {
// NOTE: This namespace has internal TensorFlow details that
// are not part of TensorFlow's public API.

BoostedTreesCalculateBestGainsPerFeature::BoostedTreesCalculateBestGainsPerFeature(const ::tensorflow::Scope& scope, ::tensorflow::Input node_id_range, ::tensorflow::InputList stats_summary_list, ::tensorflow::Input l1, ::tensorflow::Input l2, ::tensorflow::Input tree_complexity, ::tensorflow::Input min_node_weight, int64
                                                                                   max_splits) {
  if (!scope.ok()) return;
  auto _node_id_range = ::tensorflow::ops::AsNodeOut(scope, node_id_range);
  if (!scope.ok()) return;
  auto _stats_summary_list = ::tensorflow::ops::AsNodeOutList(scope, stats_summary_list);
  if (!scope.ok()) return;
  auto _l1 = ::tensorflow::ops::AsNodeOut(scope, l1);
  if (!scope.ok()) return;
  auto _l2 = ::tensorflow::ops::AsNodeOut(scope, l2);
  if (!scope.ok()) return;
  auto _tree_complexity = ::tensorflow::ops::AsNodeOut(scope, tree_complexity);
  if (!scope.ok()) return;
  auto _min_node_weight = ::tensorflow::ops::AsNodeOut(scope, min_node_weight);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("BoostedTreesCalculateBestGainsPerFeature");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "BoostedTreesCalculateBestGainsPerFeature")
                     .Input(_node_id_range)
                     .Input(_stats_summary_list)
                     .Input(_l1)
                     .Input(_l2)
                     .Input(_tree_complexity)
                     .Input(_min_node_weight)
                     .Attr("max_splits", max_splits)
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

  for (int32 i = _outputs_range["node_ids_list"].first; i < _outputs_range["node_ids_list"].second; ++i)
    this->node_ids_list.push_back(Output(ret, i));
  for (int32 i = _outputs_range["gains_list"].first; i < _outputs_range["gains_list"].second; ++i)
    this->gains_list.push_back(Output(ret, i));
  for (int32 i = _outputs_range["thresholds_list"].first; i < _outputs_range["thresholds_list"].second; ++i)
    this->thresholds_list.push_back(Output(ret, i));
  for (int32 i = _outputs_range["left_node_contribs_list"].first; i < _outputs_range["left_node_contribs_list"].second; ++i)
    this->left_node_contribs_list.push_back(Output(ret, i));
  for (int32 i = _outputs_range["right_node_contribs_list"].first; i < _outputs_range["right_node_contribs_list"].second; ++i)
    this->right_node_contribs_list.push_back(Output(ret, i));
}

BoostedTreesCreateEnsemble::BoostedTreesCreateEnsemble(const
                                                       ::tensorflow::Scope&
                                                       scope,
                                                       ::tensorflow::Input
                                                       tree_ensemble_handle,
                                                       ::tensorflow::Input
                                                       stamp_token,
                                                       ::tensorflow::Input
                                                       tree_ensemble_serialized) {
  if (!scope.ok()) return;
  auto _tree_ensemble_handle = ::tensorflow::ops::AsNodeOut(scope, tree_ensemble_handle);
  if (!scope.ok()) return;
  auto _stamp_token = ::tensorflow::ops::AsNodeOut(scope, stamp_token);
  if (!scope.ok()) return;
  auto _tree_ensemble_serialized = ::tensorflow::ops::AsNodeOut(scope, tree_ensemble_serialized);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("BoostedTreesCreateEnsemble");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "BoostedTreesCreateEnsemble")
                     .Input(_tree_ensemble_handle)
                     .Input(_stamp_token)
                     .Input(_tree_ensemble_serialized)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

BoostedTreesDeserializeEnsemble::BoostedTreesDeserializeEnsemble(const
                                                                 ::tensorflow::Scope&
                                                                 scope,
                                                                 ::tensorflow::Input
                                                                 tree_ensemble_handle,
                                                                 ::tensorflow::Input
                                                                 stamp_token,
                                                                 ::tensorflow::Input
                                                                 tree_ensemble_serialized) {
  if (!scope.ok()) return;
  auto _tree_ensemble_handle = ::tensorflow::ops::AsNodeOut(scope, tree_ensemble_handle);
  if (!scope.ok()) return;
  auto _stamp_token = ::tensorflow::ops::AsNodeOut(scope, stamp_token);
  if (!scope.ok()) return;
  auto _tree_ensemble_serialized = ::tensorflow::ops::AsNodeOut(scope, tree_ensemble_serialized);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("BoostedTreesDeserializeEnsemble");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "BoostedTreesDeserializeEnsemble")
                     .Input(_tree_ensemble_handle)
                     .Input(_stamp_token)
                     .Input(_tree_ensemble_serialized)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

BoostedTreesEnsembleResourceHandleOp::BoostedTreesEnsembleResourceHandleOp(const
                                                                           ::tensorflow::Scope&
                                                                           scope,
                                                                           const
                                                                           BoostedTreesEnsembleResourceHandleOp::Attrs&
                                                                           attrs) {
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("BoostedTreesEnsembleResourceHandleOp");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "BoostedTreesEnsembleResourceHandleOp")
                     .Attr("container", attrs.container_)
                     .Attr("shared_name", attrs.shared_name_)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->resource = Output(ret, 0);
}

BoostedTreesEnsembleResourceHandleOp::BoostedTreesEnsembleResourceHandleOp(const
                                                                           ::tensorflow::Scope&
                                                                           scope)
  : BoostedTreesEnsembleResourceHandleOp(scope, BoostedTreesEnsembleResourceHandleOp::Attrs()) {}

BoostedTreesGetEnsembleStates::BoostedTreesGetEnsembleStates(const
                                                             ::tensorflow::Scope&
                                                             scope,
                                                             ::tensorflow::Input
                                                             tree_ensemble_handle) {
  if (!scope.ok()) return;
  auto _tree_ensemble_handle = ::tensorflow::ops::AsNodeOut(scope, tree_ensemble_handle);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("BoostedTreesGetEnsembleStates");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "BoostedTreesGetEnsembleStates")
                     .Input(_tree_ensemble_handle)
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

  this->stamp_token = Output(ret, _outputs_range["stamp_token"].first);
  this->num_trees = Output(ret, _outputs_range["num_trees"].first);
  this->num_finalized_trees = Output(ret, _outputs_range["num_finalized_trees"].first);
  this->num_attempted_layers = Output(ret, _outputs_range["num_attempted_layers"].first);
  this->last_layer_nodes_range = Output(ret, _outputs_range["last_layer_nodes_range"].first);
}

BoostedTreesMakeStatsSummary::BoostedTreesMakeStatsSummary(const
                                                           ::tensorflow::Scope&
                                                           scope,
                                                           ::tensorflow::Input
                                                           node_ids,
                                                           ::tensorflow::Input
                                                           gradients,
                                                           ::tensorflow::Input
                                                           hessians,
                                                           ::tensorflow::InputList
                                                           bucketized_features_list,
                                                           int64 max_splits,
                                                           int64 num_buckets) {
  if (!scope.ok()) return;
  auto _node_ids = ::tensorflow::ops::AsNodeOut(scope, node_ids);
  if (!scope.ok()) return;
  auto _gradients = ::tensorflow::ops::AsNodeOut(scope, gradients);
  if (!scope.ok()) return;
  auto _hessians = ::tensorflow::ops::AsNodeOut(scope, hessians);
  if (!scope.ok()) return;
  auto _bucketized_features_list = ::tensorflow::ops::AsNodeOutList(scope, bucketized_features_list);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("BoostedTreesMakeStatsSummary");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "BoostedTreesMakeStatsSummary")
                     .Input(_node_ids)
                     .Input(_gradients)
                     .Input(_hessians)
                     .Input(_bucketized_features_list)
                     .Attr("max_splits", max_splits)
                     .Attr("num_buckets", num_buckets)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->stats_summary = Output(ret, 0);
}

BoostedTreesPredict::BoostedTreesPredict(const ::tensorflow::Scope& scope,
                                         ::tensorflow::Input
                                         tree_ensemble_handle,
                                         ::tensorflow::InputList
                                         bucketized_features, int64
                                         logits_dimension) {
  if (!scope.ok()) return;
  auto _tree_ensemble_handle = ::tensorflow::ops::AsNodeOut(scope, tree_ensemble_handle);
  if (!scope.ok()) return;
  auto _bucketized_features = ::tensorflow::ops::AsNodeOutList(scope, bucketized_features);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("BoostedTreesPredict");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "BoostedTreesPredict")
                     .Input(_tree_ensemble_handle)
                     .Input(_bucketized_features)
                     .Attr("logits_dimension", logits_dimension)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->logits = Output(ret, 0);
}

BoostedTreesSerializeEnsemble::BoostedTreesSerializeEnsemble(const
                                                             ::tensorflow::Scope&
                                                             scope,
                                                             ::tensorflow::Input
                                                             tree_ensemble_handle) {
  if (!scope.ok()) return;
  auto _tree_ensemble_handle = ::tensorflow::ops::AsNodeOut(scope, tree_ensemble_handle);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("BoostedTreesSerializeEnsemble");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "BoostedTreesSerializeEnsemble")
                     .Input(_tree_ensemble_handle)
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

  this->stamp_token = Output(ret, _outputs_range["stamp_token"].first);
  this->tree_ensemble_serialized = Output(ret, _outputs_range["tree_ensemble_serialized"].first);
}

BoostedTreesTrainingPredict::BoostedTreesTrainingPredict(const
                                                         ::tensorflow::Scope&
                                                         scope,
                                                         ::tensorflow::Input
                                                         tree_ensemble_handle,
                                                         ::tensorflow::Input
                                                         cached_tree_ids,
                                                         ::tensorflow::Input
                                                         cached_node_ids,
                                                         ::tensorflow::InputList
                                                         bucketized_features,
                                                         int64
                                                         logits_dimension) {
  if (!scope.ok()) return;
  auto _tree_ensemble_handle = ::tensorflow::ops::AsNodeOut(scope, tree_ensemble_handle);
  if (!scope.ok()) return;
  auto _cached_tree_ids = ::tensorflow::ops::AsNodeOut(scope, cached_tree_ids);
  if (!scope.ok()) return;
  auto _cached_node_ids = ::tensorflow::ops::AsNodeOut(scope, cached_node_ids);
  if (!scope.ok()) return;
  auto _bucketized_features = ::tensorflow::ops::AsNodeOutList(scope, bucketized_features);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("BoostedTreesTrainingPredict");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "BoostedTreesTrainingPredict")
                     .Input(_tree_ensemble_handle)
                     .Input(_cached_tree_ids)
                     .Input(_cached_node_ids)
                     .Input(_bucketized_features)
                     .Attr("logits_dimension", logits_dimension)
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

  this->partial_logits = Output(ret, _outputs_range["partial_logits"].first);
  this->tree_ids = Output(ret, _outputs_range["tree_ids"].first);
  this->node_ids = Output(ret, _outputs_range["node_ids"].first);
}

BoostedTreesUpdateEnsemble::BoostedTreesUpdateEnsemble(const
                                                       ::tensorflow::Scope&
                                                       scope,
                                                       ::tensorflow::Input
                                                       tree_ensemble_handle,
                                                       ::tensorflow::Input
                                                       feature_ids,
                                                       ::tensorflow::InputList
                                                       node_ids,
                                                       ::tensorflow::InputList
                                                       gains,
                                                       ::tensorflow::InputList
                                                       thresholds,
                                                       ::tensorflow::InputList
                                                       left_node_contribs,
                                                       ::tensorflow::InputList
                                                       right_node_contribs,
                                                       ::tensorflow::Input
                                                       max_depth,
                                                       ::tensorflow::Input
                                                       learning_rate, int64
                                                       pruning_mode) {
  if (!scope.ok()) return;
  auto _tree_ensemble_handle = ::tensorflow::ops::AsNodeOut(scope, tree_ensemble_handle);
  if (!scope.ok()) return;
  auto _feature_ids = ::tensorflow::ops::AsNodeOut(scope, feature_ids);
  if (!scope.ok()) return;
  auto _node_ids = ::tensorflow::ops::AsNodeOutList(scope, node_ids);
  if (!scope.ok()) return;
  auto _gains = ::tensorflow::ops::AsNodeOutList(scope, gains);
  if (!scope.ok()) return;
  auto _thresholds = ::tensorflow::ops::AsNodeOutList(scope, thresholds);
  if (!scope.ok()) return;
  auto _left_node_contribs = ::tensorflow::ops::AsNodeOutList(scope, left_node_contribs);
  if (!scope.ok()) return;
  auto _right_node_contribs = ::tensorflow::ops::AsNodeOutList(scope, right_node_contribs);
  if (!scope.ok()) return;
  auto _max_depth = ::tensorflow::ops::AsNodeOut(scope, max_depth);
  if (!scope.ok()) return;
  auto _learning_rate = ::tensorflow::ops::AsNodeOut(scope, learning_rate);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("BoostedTreesUpdateEnsemble");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "BoostedTreesUpdateEnsemble")
                     .Input(_tree_ensemble_handle)
                     .Input(_feature_ids)
                     .Input(_node_ids)
                     .Input(_gains)
                     .Input(_thresholds)
                     .Input(_left_node_contribs)
                     .Input(_right_node_contribs)
                     .Input(_max_depth)
                     .Input(_learning_rate)
                     .Attr("pruning_mode", pruning_mode)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->operation = Operation(ret);
  return;
}

IsBoostedTreesEnsembleInitialized::IsBoostedTreesEnsembleInitialized(const
                                                                     ::tensorflow::Scope&
                                                                     scope,
                                                                     ::tensorflow::Input
                                                                     tree_ensemble_handle) {
  if (!scope.ok()) return;
  auto _tree_ensemble_handle = ::tensorflow::ops::AsNodeOut(scope, tree_ensemble_handle);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("IsBoostedTreesEnsembleInitialized");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "IsBoostedTreesEnsembleInitialized")
                     .Input(_tree_ensemble_handle)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->is_initialized = Output(ret, 0);
}

}  // namespace internal
}  // namespace ops
}  // namespace tensorflow
