// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_CUDNN_RNN_OPS_INTERNAL_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_CUDNN_RNN_OPS_INTERNAL_H_

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

/// @defgroup cudnn_rnn_ops_internal Cudnn Rnn Ops Internal
/// @{

/// Backprop step of CudnnRNN.
///
/// Compute the backprop of both data and weights in a RNN. Takes an extra
///     "host_reserved" inupt than CudnnRNNBackprop, which is used to determine RNN
///     cudnnRNNAlgo_t and cudnnMathType_t.
///
/// rnn_mode: Indicates the type of the RNN model.
/// input_mode: Indicates whether there is a linear projection between the input and
///     the actual computation before the first layer. 'skip_input' is only allowed
///     when input_size == num_units; 'auto_select' implies 'skip_input' when
///     input_size == num_units; otherwise, it implies 'linear_input'.
/// direction: Indicates whether a bidirectional model will be used. Should be
///   "unidirectional" or "bidirectional".
/// dropout: Dropout probability. When set to 0., dropout is disabled.
/// seed: The 1st part of a seed to initialize dropout.
/// seed2: The 2nd part of a seed to initialize dropout.
/// input: A 3-D tensor with the shape of [seq_length, batch_size, input_size].
/// input_h: A 3-D tensor with the shape of [num_layer * dir, batch_size,
///     num_units].
/// input_c: For LSTM, a 3-D tensor with the shape of
///     [num_layer * dir, batch, num_units]. For other models, it is ignored.
/// params: A 1-D tensor that contains the weights and biases in an opaque layout.
///     The size must be created through CudnnRNNParamsSize, and initialized
///     separately. Note that they might not be compatible across different
///     generations. So it is a good idea to save and restore
/// output: A 3-D tensor with the shape of [seq_length, batch_size,
///     dir * num_units].
/// output_h: The same shape has input_h.
/// output_c: The same shape as input_c for LSTM. An empty tensor for other models.
/// output_backprop: A 3-D tensor with the same shape as output in the forward pass.
/// output_h_backprop: A 3-D tensor with the same shape as output_h in the forward
///     pass.
/// output_c_backprop: A 3-D tensor with the same shape as output_c in the forward
///     pass.
/// reserve_space: The same reserve_space produced in the forward operation.
/// host_reserved: The same host_reserved produced in the forward operation.
/// input_backprop: The backprop to input in the forward pass. Has the same shape
///     as input.
/// input_h_backprop: The backprop to input_h in the forward pass. Has the same
///     shape as input_h.
/// input_c_backprop: The backprop to input_c in the forward pass. Has the same
///     shape as input_c.
/// params_backprop: The backprop to the params buffer in the forward pass. Has the
///     same shape as params.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output` input_backprop
/// * `Output` input_h_backprop
/// * `Output` input_c_backprop
/// * `Output` params_backprop
class CudnnRNNBackpropV2 {
 public:
  /// Optional attribute setters for CudnnRNNBackpropV2
  struct Attrs {
    /// Defaults to "lstm"
    TF_MUST_USE_RESULT Attrs RnnMode(StringPiece x) {
      Attrs ret = *this;
      ret.rnn_mode_ = x;
      return ret;
    }

    /// Defaults to "linear_input"
    TF_MUST_USE_RESULT Attrs InputMode(StringPiece x) {
      Attrs ret = *this;
      ret.input_mode_ = x;
      return ret;
    }

    /// Defaults to "unidirectional"
    TF_MUST_USE_RESULT Attrs Direction(StringPiece x) {
      Attrs ret = *this;
      ret.direction_ = x;
      return ret;
    }

    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Dropout(float x) {
      Attrs ret = *this;
      ret.dropout_ = x;
      return ret;
    }

    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Seed(int64 x) {
      Attrs ret = *this;
      ret.seed_ = x;
      return ret;
    }

    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Seed2(int64 x) {
      Attrs ret = *this;
      ret.seed2_ = x;
      return ret;
    }

    StringPiece rnn_mode_ = "lstm";
    StringPiece input_mode_ = "linear_input";
    StringPiece direction_ = "unidirectional";
    float dropout_ = 0.0f;
    int64 seed_ = 0;
    int64 seed2_ = 0;
  };
  CudnnRNNBackpropV2(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
                   ::tensorflow::Input input_h, ::tensorflow::Input input_c,
                   ::tensorflow::Input params, ::tensorflow::Input output,
                   ::tensorflow::Input output_h, ::tensorflow::Input output_c,
                   ::tensorflow::Input output_backprop, ::tensorflow::Input
                   output_h_backprop, ::tensorflow::Input output_c_backprop,
                   ::tensorflow::Input reserve_space, ::tensorflow::Input
                   host_reserved);
  CudnnRNNBackpropV2(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
                   ::tensorflow::Input input_h, ::tensorflow::Input input_c,
                   ::tensorflow::Input params, ::tensorflow::Input output,
                   ::tensorflow::Input output_h, ::tensorflow::Input output_c,
                   ::tensorflow::Input output_backprop, ::tensorflow::Input
                   output_h_backprop, ::tensorflow::Input output_c_backprop,
                   ::tensorflow::Input reserve_space, ::tensorflow::Input
                   host_reserved, const CudnnRNNBackpropV2::Attrs& attrs);

  static Attrs RnnMode(StringPiece x) {
    return Attrs().RnnMode(x);
  }
  static Attrs InputMode(StringPiece x) {
    return Attrs().InputMode(x);
  }
  static Attrs Direction(StringPiece x) {
    return Attrs().Direction(x);
  }
  static Attrs Dropout(float x) {
    return Attrs().Dropout(x);
  }
  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }

  ::tensorflow::Output input_backprop;
  ::tensorflow::Output input_h_backprop;
  ::tensorflow::Output input_c_backprop;
  ::tensorflow::Output params_backprop;
};

/// A RNN backed by cuDNN.
///
/// Computes the RNN from the input and initial states, with respect to the params
/// buffer. Produces one extra output "host_reserved" than CudnnRNN.
///
/// rnn_mode: Indicates the type of the RNN model.
/// input_mode: Indicates whether there is a linear projection between the input and
///   the actual computation before the first layer. 'skip_input' is only allowed
///   when input_size == num_units; 'auto_select' implies 'skip_input' when
///   input_size == num_units; otherwise, it implies 'linear_input'.
/// direction: Indicates whether a bidirectional model will be used. Should be
///   "unidirectional" or "bidirectional".
/// dropout: Dropout probability. When set to 0., dropout is disabled.
/// seed: The 1st part of a seed to initialize dropout.
/// seed2: The 2nd part of a seed to initialize dropout.
/// input: A 3-D tensor with the shape of [seq_length, batch_size, input_size].
/// input_h: A 3-D tensor with the shape of [num_layer * dir, batch_size,
///     num_units].
/// input_c: For LSTM, a 3-D tensor with the shape of
///     [num_layer * dir, batch, num_units]. For other models, it is ignored.
/// params: A 1-D tensor that contains the weights and biases in an opaque layout.
///     The size must be created through CudnnRNNParamsSize, and initialized
///     separately. Note that they might not be compatible across different
///     generations. So it is a good idea to save and restore
/// output: A 3-D tensor with the shape of [seq_length, batch_size,
///     dir * num_units].
/// output_h: The same shape has input_h.
/// output_c: The same shape as input_c for LSTM. An empty tensor for other models.
/// is_training: Indicates whether this operation is used for inferenece or
///   training.
/// reserve_space: An opaque tensor that can be used in backprop calculation. It
///   is only produced if is_training is true.
/// host_reserved: An opaque tensor that can be used in backprop calculation. It is
///   only produced if is_training is true. It is output on host memory rather than
///   device memory.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output` output
/// * `Output` output_h
/// * `Output` output_c
/// * `Output` reserve_space
/// * `Output` host_reserved
class CudnnRNNV2 {
 public:
  /// Optional attribute setters for CudnnRNNV2
  struct Attrs {
    /// Defaults to "lstm"
    TF_MUST_USE_RESULT Attrs RnnMode(StringPiece x) {
      Attrs ret = *this;
      ret.rnn_mode_ = x;
      return ret;
    }

    /// Defaults to "linear_input"
    TF_MUST_USE_RESULT Attrs InputMode(StringPiece x) {
      Attrs ret = *this;
      ret.input_mode_ = x;
      return ret;
    }

    /// Defaults to "unidirectional"
    TF_MUST_USE_RESULT Attrs Direction(StringPiece x) {
      Attrs ret = *this;
      ret.direction_ = x;
      return ret;
    }

    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Dropout(float x) {
      Attrs ret = *this;
      ret.dropout_ = x;
      return ret;
    }

    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Seed(int64 x) {
      Attrs ret = *this;
      ret.seed_ = x;
      return ret;
    }

    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs Seed2(int64 x) {
      Attrs ret = *this;
      ret.seed2_ = x;
      return ret;
    }

    /// Defaults to true
    TF_MUST_USE_RESULT Attrs IsTraining(bool x) {
      Attrs ret = *this;
      ret.is_training_ = x;
      return ret;
    }

    StringPiece rnn_mode_ = "lstm";
    StringPiece input_mode_ = "linear_input";
    StringPiece direction_ = "unidirectional";
    float dropout_ = 0.0f;
    int64 seed_ = 0;
    int64 seed2_ = 0;
    bool is_training_ = true;
  };
  CudnnRNNV2(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
           ::tensorflow::Input input_h, ::tensorflow::Input input_c,
           ::tensorflow::Input params);
  CudnnRNNV2(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
           ::tensorflow::Input input_h, ::tensorflow::Input input_c,
           ::tensorflow::Input params, const CudnnRNNV2::Attrs& attrs);

  static Attrs RnnMode(StringPiece x) {
    return Attrs().RnnMode(x);
  }
  static Attrs InputMode(StringPiece x) {
    return Attrs().InputMode(x);
  }
  static Attrs Direction(StringPiece x) {
    return Attrs().Direction(x);
  }
  static Attrs Dropout(float x) {
    return Attrs().Dropout(x);
  }
  static Attrs Seed(int64 x) {
    return Attrs().Seed(x);
  }
  static Attrs Seed2(int64 x) {
    return Attrs().Seed2(x);
  }
  static Attrs IsTraining(bool x) {
    return Attrs().IsTraining(x);
  }

  ::tensorflow::Output output;
  ::tensorflow::Output output_h;
  ::tensorflow::Output output_c;
  ::tensorflow::Output reserve_space;
  ::tensorflow::Output host_reserved;
};

}  // namespace internal
}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_CUDNN_RNN_OPS_INTERNAL_H_
