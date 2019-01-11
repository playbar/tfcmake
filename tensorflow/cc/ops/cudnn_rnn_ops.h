// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_CUDNN_RNN_OPS_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_CUDNN_RNN_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

/// @defgroup cudnn_rnn_ops Cudnn Rnn Ops
/// @{

/// A RNN backed by cuDNN.
///
/// Computes the RNN from the input and initial states, with respect to the params
/// buffer.
///
/// rnn_mode: Indicates the type of the RNN model.
/// input_mode: Indicate whether there is a linear projection between the input and
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
///   is only produced if is_training is false.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output` output
/// * `Output` output_h
/// * `Output` output_c
/// * `Output` reserve_space
class CudnnRNN {
 public:
  /// Optional attribute setters for CudnnRNN
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
  CudnnRNN(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
         ::tensorflow::Input input_h, ::tensorflow::Input input_c,
         ::tensorflow::Input params);
  CudnnRNN(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
         ::tensorflow::Input input_h, ::tensorflow::Input input_c,
         ::tensorflow::Input params, const CudnnRNN::Attrs& attrs);

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
};

/// Backprop step of CudnnRNN.
///
/// Compute the backprop of both data and weights in a RNN.
///
/// rnn_mode: Indicates the type of the RNN model.
/// input_mode: Indicate whether there is a linear projection between the input and
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
/// reserve_space: The same reserve_space produced in for forward operation.
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
class CudnnRNNBackprop {
 public:
  /// Optional attribute setters for CudnnRNNBackprop
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
  CudnnRNNBackprop(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
                 ::tensorflow::Input input_h, ::tensorflow::Input input_c,
                 ::tensorflow::Input params, ::tensorflow::Input output,
                 ::tensorflow::Input output_h, ::tensorflow::Input output_c,
                 ::tensorflow::Input output_backprop, ::tensorflow::Input
                 output_h_backprop, ::tensorflow::Input output_c_backprop,
                 ::tensorflow::Input reserve_space);
  CudnnRNNBackprop(const ::tensorflow::Scope& scope, ::tensorflow::Input input,
                 ::tensorflow::Input input_h, ::tensorflow::Input input_c,
                 ::tensorflow::Input params, ::tensorflow::Input output,
                 ::tensorflow::Input output_h, ::tensorflow::Input output_c,
                 ::tensorflow::Input output_backprop, ::tensorflow::Input
                 output_h_backprop, ::tensorflow::Input output_c_backprop,
                 ::tensorflow::Input reserve_space, const
                 CudnnRNNBackprop::Attrs& attrs);

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

/// Converts CudnnRNN params from canonical form to usable form.
///
/// Writes a set of weights into the opaque params buffer so they can be used in
/// upcoming training or inferences.
///
/// Note that the params buffer may not be compatible across different GPUs. So any
/// save and restoration should be converted to and from the canonical weights and
/// biases.
///
/// num_layers: Specifies the number of layers in the RNN model.
/// num_units: Specifies the size of the hidden state.
/// input_size: Specifies the size of the input state.
/// weights: the canonical form of weights that can be used for saving
///     and restoration. They are more likely to be compatible across different
///     generations.
/// biases: the canonical form of biases that can be used for saving
///     and restoration. They are more likely to be compatible across different
///     generations.
/// num_params: number of parameter sets for all layers.
///     Each layer may contain multiple parameter sets, with each set consisting of
///     a weight matrix and a bias vector.
/// rnn_mode: Indicates the type of the RNN model.
/// input_mode: Indicate whether there is a linear projection between the input and
///     The actual computation before the first layer. 'skip_input' is only allowed
///     when input_size == num_units; 'auto_select' implies 'skip_input' when
///     input_size == num_units; otherwise, it implies 'linear_input'.
/// direction: Indicates whether a bidirectional model will be used.
///     dir = (direction == bidirectional) ? 2 : 1
/// dropout: dropout probability. When set to 0., dropout is disabled.
/// seed: the 1st part of a seed to initialize dropout.
/// seed2: the 2nd part of a seed to initialize dropout.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The params tensor.
class CudnnRNNCanonicalToParams {
 public:
  /// Optional attribute setters for CudnnRNNCanonicalToParams
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
  CudnnRNNCanonicalToParams(const ::tensorflow::Scope& scope, ::tensorflow::Input
                          num_layers, ::tensorflow::Input num_units,
                          ::tensorflow::Input input_size,
                          ::tensorflow::InputList weights,
                          ::tensorflow::InputList biases);
  CudnnRNNCanonicalToParams(const ::tensorflow::Scope& scope, ::tensorflow::Input
                          num_layers, ::tensorflow::Input num_units,
                          ::tensorflow::Input input_size,
                          ::tensorflow::InputList weights,
                          ::tensorflow::InputList biases, const
                          CudnnRNNCanonicalToParams::Attrs& attrs);
  operator ::tensorflow::Output() const { return params; }
  operator ::tensorflow::Input() const { return params; }
  ::tensorflow::Node* node() const { return params.node(); }

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

  ::tensorflow::Output params;
};

/// Computes size of weights that can be used by a Cudnn RNN model.
///
/// Return the params size that can be used by the Cudnn RNN model. Subsequent
/// weight allocation and initialization should use this size.
///
/// num_layers: Specifies the number of layers in the RNN model.
/// num_units: Specifies the size of the hidden state.
/// input_size: Specifies the size of the input state.
/// rnn_mode: Indicates the type of the RNN model.
/// input_mode: Indicate whether there is a linear projection between the input and
///   The actual computation before the first layer. 'skip_input' is only allowed
///   when input_size == num_units; 'auto_select' implies 'skip_input' when
///   input_size == num_units; otherwise, it implies 'linear_input'.
/// direction: Indicates whether a bidirectional model will be used.
///   dir = (direction == bidirectional) ? 2 : 1
/// dropout: dropout probability. When set to 0., dropout is disabled.
/// seed: the 1st part of a seed to initialize dropout.
/// seed2: the 2nd part of a seed to initialize dropout.
/// params_size: The size of the params buffer that should be allocated and
///   initialized for this RNN model. Note that this params buffer may not be
///   compatible across GPUs. Please use CudnnRNNParamsWeights and
///   CudnnRNNParamsBiases to save and restore them in a way that is compatible
///   across different runs.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The params_size tensor.
class CudnnRNNParamsSize {
 public:
  /// Optional attribute setters for CudnnRNNParamsSize
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
  CudnnRNNParamsSize(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   num_layers, ::tensorflow::Input num_units,
                   ::tensorflow::Input input_size, DataType T, DataType S);
  CudnnRNNParamsSize(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   num_layers, ::tensorflow::Input num_units,
                   ::tensorflow::Input input_size, DataType T, DataType S,
                   const CudnnRNNParamsSize::Attrs& attrs);
  operator ::tensorflow::Output() const { return params_size; }
  operator ::tensorflow::Input() const { return params_size; }
  ::tensorflow::Node* node() const { return params_size.node(); }

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

  ::tensorflow::Output params_size;
};

/// Retrieves CudnnRNN params in canonical form.
///
/// Retrieves a set of weights from the opaque params buffer that can be saved and
/// restored in a way compatible with future runs.
///
/// Note that the params buffer may not be compatible across different GPUs. So any
/// save and restoration should be converted to and from the canonical weights and
/// biases.
///
/// num_layers: Specifies the number of layers in the RNN model.
/// num_units: Specifies the size of the hidden state.
/// input_size: Specifies the size of the input state.
/// num_params: number of parameter sets for all layers.
///     Each layer may contain multiple parameter sets, with each set consisting of
///     a weight matrix and a bias vector.
/// weights: the canonical form of weights that can be used for saving
///     and restoration. They are more likely to be compatible across different
///     generations.
/// biases: the canonical form of biases that can be used for saving
///     and restoration. They are more likely to be compatible across different
///     generations.
/// rnn_mode: Indicates the type of the RNN model.
/// input_mode: Indicate whether there is a linear projection between the input and
///     The actual computation before the first layer. 'skip_input' is only allowed
///     when input_size == num_units; 'auto_select' implies 'skip_input' when
///     input_size == num_units; otherwise, it implies 'linear_input'.
/// direction: Indicates whether a bidirectional model will be used.
///     dir = (direction == bidirectional) ? 2 : 1
/// dropout: dropout probability. When set to 0., dropout is disabled.
/// seed: the 1st part of a seed to initialize dropout.
/// seed2: the 2nd part of a seed to initialize dropout.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `OutputList` weights
/// * `OutputList` biases
class CudnnRNNParamsToCanonical {
 public:
  /// Optional attribute setters for CudnnRNNParamsToCanonical
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
  CudnnRNNParamsToCanonical(const ::tensorflow::Scope& scope, ::tensorflow::Input
                          num_layers, ::tensorflow::Input num_units,
                          ::tensorflow::Input input_size, ::tensorflow::Input
                          params, int64 num_params);
  CudnnRNNParamsToCanonical(const ::tensorflow::Scope& scope, ::tensorflow::Input
                          num_layers, ::tensorflow::Input num_units,
                          ::tensorflow::Input input_size, ::tensorflow::Input
                          params, int64 num_params, const
                          CudnnRNNParamsToCanonical::Attrs& attrs);

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

  ::tensorflow::OutputList weights;
  ::tensorflow::OutputList biases;
};

/// @}

}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_CUDNN_RNN_OPS_H_
