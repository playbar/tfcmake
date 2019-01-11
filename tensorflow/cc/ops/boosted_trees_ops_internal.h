// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_BOOSTED_TREES_OPS_INTERNAL_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_BOOSTED_TREES_OPS_INTERNAL_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {
namespace internal {
// NOTE: This namespace has internal TensorFlow details that
// are not part of TensorFlow's public API.

/// @defgroup boosted_trees_ops_internal Boosted Trees Ops Internal
/// @{

/// Calculates gains for each feature and returns the best possible split information for the feature.
///
/// The split information is the best threshold (bucket id), gains and left/right node contributions per node for each feature.
///
/// It is possible that not all nodes can be split on each feature. Hence, the list of possible nodes can differ between the features. Therefore, we return `node_ids_list` for each feature, containing the list of nodes that this feature can be used to split.
///
/// In this manner, the output is the best split per features and per node, so that it needs to be combined later to produce the best split for each node (among all possible features).
///
/// The length of output lists are all of the same length, `num_features`.
/// The output shapes are compatible in a way that the first dimension of all tensors of all lists are the same and equal to the number of possible split nodes for each feature.
///
/// Arguments:
/// * scope: A Scope object
/// * node_id_range: A Rank 1 tensor (shape=[2]) to specify the range [first, last) of node ids to process within `stats_summary_list`. The nodes are iterated between the two nodes specified by the tensor, as like `for node_id in range(node_id_range[0], node_id_range[1])` (Note that the last index node_id_range[1] is exclusive).
/// * stats_summary_list: A list of Rank 3 tensor (#shape=[max_splits, bucket, 2]) for accumulated stats summary (gradient/hessian) per node per buckets for each feature. The first dimension of the tensor is the maximum number of splits, and thus not all elements of it will be used, but only the indexes specified by node_ids will be used.
/// * l1: l1 regularization factor on leaf weights, per instance based.
/// * l2: l2 regularization factor on leaf weights, per instance based.
/// * tree_complexity: adjustment to the gain, per leaf based.
/// * min_node_weight: mininum avg of hessians in a node before required for the node to be considered for splitting.
/// * max_splits: the number of nodes that can be split in the whole tree. Used as a dimension of output tensors.
///
/// Returns:
/// * `OutputList` node_ids_list: An output list of Rank 1 tensors indicating possible split node ids for each feature. The length of the list is num_features, but each tensor has different size as each feature provides different possible nodes. See above for details like shapes and sizes.
/// * `OutputList` gains_list: An output list of Rank 1 tensors indicating the best gains for each feature to split for certain nodes. See above for details like shapes and sizes.
/// * `OutputList` thresholds_list: An output list of Rank 1 tensors indicating the bucket id to compare with (as a threshold) for split in each node. See above for details like shapes and sizes.
/// * `OutputList` left_node_contribs_list: A list of Rank 2 tensors indicating the contribution of the left nodes when branching from parent nodes (given by the tensor element in the output node_ids_list) to the left direction by the given threshold for each feature. This value will be used to make the left node value by adding to the parent node value. Second dimension size is 1 for 1-dimensional logits, but would be larger for multi-class problems. See above for details like shapes and sizes.
/// * `OutputList` right_node_contribs_list: A list of Rank 2 tensors, with the same shape/conditions as left_node_contribs_list, but just that the value is for the right node.
class BoostedTreesCalculateBestGainsPerFeature {
 public:
  BoostedTreesCalculateBestGainsPerFeature(const ::tensorflow::Scope& scope,
                                         ::tensorflow::Input node_id_range,
                                         ::tensorflow::InputList
                                         stats_summary_list,
                                         ::tensorflow::Input l1,
                                         ::tensorflow::Input l2,
                                         ::tensorflow::Input tree_complexity,
                                         ::tensorflow::Input min_node_weight,
                                         int64 max_splits);

  ::tensorflow::OutputList node_ids_list;
  ::tensorflow::OutputList gains_list;
  ::tensorflow::OutputList thresholds_list;
  ::tensorflow::OutputList left_node_contribs_list;
  ::tensorflow::OutputList right_node_contribs_list;
};

/// Creates a tree ensemble model and returns a handle to it.
///
/// Arguments:
/// * scope: A Scope object
/// * tree_ensemble_handle: Handle to the tree ensemble resource to be created.
/// * stamp_token: Token to use as the initial value of the resource stamp.
/// * tree_ensemble_serialized: Serialized proto of the tree ensemble.
///
/// Returns:
/// * the created `Operation`
class BoostedTreesCreateEnsemble {
 public:
  BoostedTreesCreateEnsemble(const ::tensorflow::Scope& scope,
                           ::tensorflow::Input tree_ensemble_handle,
                           ::tensorflow::Input stamp_token, ::tensorflow::Input
                           tree_ensemble_serialized);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Deserializes a serialized tree ensemble config and replaces current tree
///
/// ensemble.
///
/// Arguments:
/// * scope: A Scope object
/// * tree_ensemble_handle: Handle to the tree ensemble.
/// * stamp_token: Token to use as the new value of the resource stamp.
/// * tree_ensemble_serialized: Serialized proto of the ensemble.
///
/// Returns:
/// * the created `Operation`
class BoostedTreesDeserializeEnsemble {
 public:
  BoostedTreesDeserializeEnsemble(const ::tensorflow::Scope& scope,
                                ::tensorflow::Input tree_ensemble_handle,
                                ::tensorflow::Input stamp_token,
                                ::tensorflow::Input tree_ensemble_serialized);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Creates a handle to a BoostedTreesEnsembleResource
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The resource tensor.
class BoostedTreesEnsembleResourceHandleOp {
 public:
  /// Optional attribute setters for BoostedTreesEnsembleResourceHandleOp
  struct Attrs {
    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs Container(StringPiece x) {
      Attrs ret = *this;
      ret.container_ = x;
      return ret;
    }

    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs SharedName(StringPiece x) {
      Attrs ret = *this;
      ret.shared_name_ = x;
      return ret;
    }

    StringPiece container_ = "";
    StringPiece shared_name_ = "";
  };
  BoostedTreesEnsembleResourceHandleOp(const ::tensorflow::Scope& scope);
  BoostedTreesEnsembleResourceHandleOp(const ::tensorflow::Scope& scope, const
                                     BoostedTreesEnsembleResourceHandleOp::Attrs&
                                     attrs);
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

/// Retrieves the tree ensemble resource stamp token, number of trees and growing statistics.
///
/// Arguments:
/// * scope: A Scope object
/// * tree_ensemble_handle: Handle to the tree ensemble.
///
/// Returns:
/// * `Output` stamp_token: Stamp token of the tree ensemble resource.
/// * `Output` num_trees: The number of trees in the tree ensemble resource.
/// * `Output` num_finalized_trees: The number of trees that were finished successfully.
/// * `Output` num_attempted_layers: The number of layers we attempted to build (but not necessarily succeeded).
/// * `Output` last_layer_nodes_range: Rank size 2 tensor that contains start and end ids of the nodes in the latest
/// layer.
class BoostedTreesGetEnsembleStates {
 public:
  BoostedTreesGetEnsembleStates(const ::tensorflow::Scope& scope,
                              ::tensorflow::Input tree_ensemble_handle);

  ::tensorflow::Output stamp_token;
  ::tensorflow::Output num_trees;
  ::tensorflow::Output num_finalized_trees;
  ::tensorflow::Output num_attempted_layers;
  ::tensorflow::Output last_layer_nodes_range;
};

/// Makes the summary of accumulated stats for the batch.
///
/// The summary stats contains gradients and hessians accumulated into the corresponding node and bucket for each example.
///
/// Arguments:
/// * scope: A Scope object
/// * node_ids: int32 Rank 1 Tensor containing node ids, which each example falls into for the requested layer.
/// * gradients: float32; Rank 2 Tensor (shape=[#examples, 1]) for gradients.
/// * hessians: float32; Rank 2 Tensor (shape=[#examples, 1]) for hessians.
/// * bucketized_features_list: int32 list of Rank 1 Tensors, each containing the bucketized feature (for each feature column).
/// * max_splits: int; the maximum number of splits possible in the whole tree.
/// * num_buckets: int; equals to the maximum possible value of bucketized feature.
///
/// Returns:
/// * `Output`: output Rank 4 Tensor (shape=[#features, #splits, #buckets, 2]) containing accumulated stats put into the corresponding node and bucket. The first index of 4th dimension refers to gradients, and the second to hessians.
class BoostedTreesMakeStatsSummary {
 public:
  BoostedTreesMakeStatsSummary(const ::tensorflow::Scope& scope,
                             ::tensorflow::Input node_ids, ::tensorflow::Input
                             gradients, ::tensorflow::Input hessians,
                             ::tensorflow::InputList bucketized_features_list,
                             int64 max_splits, int64 num_buckets);
  operator ::tensorflow::Output() const { return stats_summary; }
  operator ::tensorflow::Input() const { return stats_summary; }
  ::tensorflow::Node* node() const { return stats_summary.node(); }

  ::tensorflow::Output stats_summary;
};

/// Runs multiple additive regression ensemble predictors on input instances and
///
/// computes the logits. It is designed to be used during prediction.
/// It traverses all the trees and calculates the final score for each instance.
///
/// Arguments:
/// * scope: A Scope object
/// * bucketized_features: A list of rank 1 Tensors containing bucket id for each
/// feature.
/// * logits_dimension: scalar, dimension of the logits, to be used for partial logits
/// shape.
///
/// Returns:
/// * `Output`: Output rank 2 Tensor containing logits for each example.
class BoostedTreesPredict {
 public:
  BoostedTreesPredict(const ::tensorflow::Scope& scope, ::tensorflow::Input
                    tree_ensemble_handle, ::tensorflow::InputList
                    bucketized_features, int64 logits_dimension);
  operator ::tensorflow::Output() const { return logits; }
  operator ::tensorflow::Input() const { return logits; }
  ::tensorflow::Node* node() const { return logits.node(); }

  ::tensorflow::Output logits;
};

/// Serializes the tree ensemble to a proto.
///
/// Arguments:
/// * scope: A Scope object
/// * tree_ensemble_handle: Handle to the tree ensemble.
///
/// Returns:
/// * `Output` stamp_token: Stamp token of the tree ensemble resource.
/// * `Output` tree_ensemble_serialized: Serialized proto of the ensemble.
class BoostedTreesSerializeEnsemble {
 public:
  BoostedTreesSerializeEnsemble(const ::tensorflow::Scope& scope,
                              ::tensorflow::Input tree_ensemble_handle);

  ::tensorflow::Output stamp_token;
  ::tensorflow::Output tree_ensemble_serialized;
};

/// Runs multiple additive regression ensemble predictors on input instances and
///
/// computes the update to cached logits. It is designed to be used during training.
/// It traverses the trees starting from cached tree id and cached node id and
/// calculates the updates to be pushed to the cache.
///
/// Arguments:
/// * scope: A Scope object
/// * cached_tree_ids: Rank 1 Tensor containing cached tree ids which is the starting
/// tree of prediction.
/// * cached_node_ids: Rank 1 Tensor containing cached node id which is the starting
/// node of prediction.
/// * bucketized_features: A list of rank 1 Tensors containing bucket id for each
/// feature.
/// * logits_dimension: scalar, dimension of the logits, to be used for partial logits
/// shape.
///
/// Returns:
/// * `Output` partial_logits: Rank 2 Tensor containing logits update (with respect to cached
/// values stored) for each example.
/// * `Output` tree_ids: Rank 1 Tensor containing new tree ids for each example.
/// * `Output` node_ids: Rank 1 Tensor containing new node ids in the new tree_ids.
class BoostedTreesTrainingPredict {
 public:
  BoostedTreesTrainingPredict(const ::tensorflow::Scope& scope,
                            ::tensorflow::Input tree_ensemble_handle,
                            ::tensorflow::Input cached_tree_ids,
                            ::tensorflow::Input cached_node_ids,
                            ::tensorflow::InputList bucketized_features, int64
                            logits_dimension);

  ::tensorflow::Output partial_logits;
  ::tensorflow::Output tree_ids;
  ::tensorflow::Output node_ids;
};

/// Updates the tree ensemble by either adding a layer to the last tree being grown
///
/// or by starting a new tree.
///
/// Arguments:
/// * scope: A Scope object
/// * tree_ensemble_handle: Handle to the ensemble variable.
/// * feature_ids: Rank 1 tensor with ids for each feature. This is the real id of
/// the feature that will be used in the split.
/// * node_ids: List of rank 1 tensors representing the nodes for which this feature
/// has a split.
/// * gains: List of rank 1 tensors representing the gains for each of the feature's
/// split.
/// * thresholds: List of rank 1 tensors representing the thesholds for each of the
/// feature's split.
/// * left_node_contribs: List of rank 2 tensors with left leaf contribs for each of
/// the feature's splits. Will be added to the previous node values to constitute
/// the values of the left nodes.
/// * right_node_contribs: List of rank 2 tensors with right leaf contribs for each
/// of the feature's splits. Will be added to the previous node values to constitute
/// the values of the right nodes.
/// * max_depth: Max depth of the tree to build.
/// * learning_rate: shrinkage const for each new tree.
/// * pruning_mode: 0-No pruning, 1-Pre-pruning, 2-Post-pruning.
///
/// Returns:
/// * the created `Operation`
class BoostedTreesUpdateEnsemble {
 public:
  BoostedTreesUpdateEnsemble(const ::tensorflow::Scope& scope,
                           ::tensorflow::Input tree_ensemble_handle,
                           ::tensorflow::Input feature_ids,
                           ::tensorflow::InputList node_ids,
                           ::tensorflow::InputList gains,
                           ::tensorflow::InputList thresholds,
                           ::tensorflow::InputList left_node_contribs,
                           ::tensorflow::InputList right_node_contribs,
                           ::tensorflow::Input max_depth, ::tensorflow::Input
                           learning_rate, int64 pruning_mode);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// Checks whether a tree ensemble has been initialized.
///
/// Arguments:
/// * scope: A Scope object
/// * tree_ensemble_handle: Handle to the tree ensemble resouce.
///
/// Returns:
/// * `Output`: output boolean on whether it is initialized or not.
class IsBoostedTreesEnsembleInitialized {
 public:
  IsBoostedTreesEnsembleInitialized(const ::tensorflow::Scope& scope,
                                  ::tensorflow::Input tree_ensemble_handle);
  operator ::tensorflow::Output() const { return is_initialized; }
  operator ::tensorflow::Input() const { return is_initialized; }
  ::tensorflow::Node* node() const { return is_initialized.node(); }

  ::tensorflow::Output is_initialized;
};

}  // namespace internal
}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_BOOSTED_TREES_OPS_INTERNAL_H_
