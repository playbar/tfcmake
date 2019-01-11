// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_BATCH_OPS_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_BATCH_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

/// @defgroup batch_ops Batch Ops
/// @{

/// Batches all input tensors nondeterministically.
///
/// When many instances of this Op are being run concurrently with the same
/// container/shared_name in the same device, some will output zero-shaped Tensors
/// and others will output Tensors of size up to max_batch_size.
///
/// All Tensors in in_tensors are batched together (so, for example, labels and
/// features should be batched with a single instance of this operation.
///
/// Each invocation of batch emits an `id` scalar which will be used to identify
/// this particular invocation when doing unbatch or its gradient.
///
/// Each op which emits a non-empty batch will also emit a non-empty batch_index
/// Tensor, which, is a [K, 3] matrix where each row contains the invocation's id,
/// start, and length of elements of each set of Tensors present in batched_tensors.
///
/// Batched tensors are concatenated along the first dimension, and all tensors in
/// in_tensors must have the first dimension of the same size.
///
/// in_tensors: The tensors to be batched.
/// num_batch_threads: Number of scheduling threads for processing batches of work.
///  Determines the number of batches processed in parallel.
/// max_batch_size: Batch sizes will never be bigger than this.
/// batch_timeout_micros: Maximum number of microseconds to wait before outputting
///  an incomplete batch.
/// allowed_batch_sizes: Optional list of allowed batch sizes. If left empty, does
///  nothing. Otherwise, supplies a list of batch sizes, causing the op to pad
///  batches up to one of those sizes. The entries must increase monotonically, and
///  the final entry must equal max_batch_size.
/// grad_timeout_micros: The timeout to use for the gradient. See Unbatch.
/// batched_tensors: Either empty tensors or a batch of concatenated Tensors.
/// batch_index: If out_tensors is non-empty, has information to invert it.
/// container: Controls the scope of sharing of this batch.
/// id: always contains a scalar with a unique ID for this invocation of Batch.
/// shared_name: Concurrently running instances of batch in the same device with the
///  same container and shared_name will batch their elements together. If left
///  empty, the op name will be used as the shared name.
/// T: the types of tensors to be batched.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `OutputList` batched_tensors
/// * `Output` batch_index
/// * `Output` id
class Batch {
 public:
  /// Optional attribute setters for Batch
  struct Attrs {
    /// Defaults to 10
    TF_MUST_USE_RESULT Attrs MaxEnqueuedBatches(int64 x) {
      Attrs ret = *this;
      ret.max_enqueued_batches_ = x;
      return ret;
    }

    /// Defaults to []
    TF_MUST_USE_RESULT Attrs AllowedBatchSizes(const gtl::ArraySlice<int>& x) {
      Attrs ret = *this;
      ret.allowed_batch_sizes_ = x;
      return ret;
    }

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

    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs BatchingQueue(StringPiece x) {
      Attrs ret = *this;
      ret.batching_queue_ = x;
      return ret;
    }

    int64 max_enqueued_batches_ = 10;
    gtl::ArraySlice<int> allowed_batch_sizes_ = {};
    StringPiece container_ = "";
    StringPiece shared_name_ = "";
    StringPiece batching_queue_ = "";
  };
  Batch(const ::tensorflow::Scope& scope, ::tensorflow::InputList in_tensors,
      int64 num_batch_threads, int64 max_batch_size, int64
      batch_timeout_micros, int64 grad_timeout_micros);
  Batch(const ::tensorflow::Scope& scope, ::tensorflow::InputList in_tensors,
      int64 num_batch_threads, int64 max_batch_size, int64
      batch_timeout_micros, int64 grad_timeout_micros, const Batch::Attrs&
      attrs);

  static Attrs MaxEnqueuedBatches(int64 x) {
    return Attrs().MaxEnqueuedBatches(x);
  }
  static Attrs AllowedBatchSizes(const gtl::ArraySlice<int>& x) {
    return Attrs().AllowedBatchSizes(x);
  }
  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }
  static Attrs BatchingQueue(StringPiece x) {
    return Attrs().BatchingQueue(x);
  }

  ::tensorflow::OutputList batched_tensors;
  ::tensorflow::Output batch_index;
  ::tensorflow::Output id;
};

/// Reverses the operation of Batch for a single output Tensor.
///
/// An instance of Unbatch either receives an empty batched_tensor, in which case it
/// asynchronously waits until the values become available from a concurrently
/// running instance of Unbatch with the same container and shared_name, or receives
/// a non-empty batched_tensor in which case it finalizes all other concurrently
/// running instances and outputs its own element from the batch.
///
/// batched_tensor: The possibly transformed output of Batch. The size of the first
///  dimension should remain unchanged by the transformations for the operation to
///  work.
/// batch_index: The matching batch_index obtained from Batch.
/// id: The id scalar emitted by Batch.
/// unbatched_tensor: The Tensor corresponding to this execution.
/// timeout_micros: Maximum amount of time (in microseconds) to wait to receive the
///  batched input tensor associated with a given invocation of the op.
/// container: Container to control resource sharing.
/// shared_name: Instances of Unbatch with the same container and shared_name are
///  assumed to possibly belong to the same batch. If left empty, the op name will
///  be used as the shared name.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The unbatched_tensor tensor.
class Unbatch {
 public:
  /// Optional attribute setters for Unbatch
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
  Unbatch(const ::tensorflow::Scope& scope, ::tensorflow::Input batched_tensor,
        ::tensorflow::Input batch_index, ::tensorflow::Input id, int64
        timeout_micros);
  Unbatch(const ::tensorflow::Scope& scope, ::tensorflow::Input batched_tensor,
        ::tensorflow::Input batch_index, ::tensorflow::Input id, int64
        timeout_micros, const Unbatch::Attrs& attrs);
  operator ::tensorflow::Output() const { return unbatched_tensor; }
  operator ::tensorflow::Input() const { return unbatched_tensor; }
  ::tensorflow::Node* node() const { return unbatched_tensor.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::Output unbatched_tensor;
};

/// Gradient of Unbatch.
///
/// Acts like Batch but using the given batch_index index of batching things as they
/// become available. This ensures that the gradients are propagated back in the
/// same session which did the forward pass.
///
/// original_input: The input to the Unbatch operation this is the gradient of.
/// batch_index: The batch_index given to the Unbatch operation this is the gradient
/// of.
/// grad: The downstream gradient.
/// id: The id scalar emitted by Batch.
/// batched_grad: The return value, either an empty tensor or the batched gradient.
/// container: Container to control resource sharing.
/// shared_name: Instances of UnbatchGrad with the same container and shared_name
///  are assumed to possibly belong to the same batch. If left empty, the op name
///  will be used as the shared name.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The batched_grad tensor.
class UnbatchGrad {
 public:
  /// Optional attribute setters for UnbatchGrad
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
  UnbatchGrad(const ::tensorflow::Scope& scope, ::tensorflow::Input
            original_input, ::tensorflow::Input batch_index,
            ::tensorflow::Input grad, ::tensorflow::Input id);
  UnbatchGrad(const ::tensorflow::Scope& scope, ::tensorflow::Input
            original_input, ::tensorflow::Input batch_index,
            ::tensorflow::Input grad, ::tensorflow::Input id, const
            UnbatchGrad::Attrs& attrs);
  operator ::tensorflow::Output() const { return batched_grad; }
  operator ::tensorflow::Input() const { return batched_grad; }
  ::tensorflow::Node* node() const { return batched_grad.node(); }

  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }
  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }

  ::tensorflow::Output batched_grad;
};

/// @}

}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_BATCH_OPS_H_
