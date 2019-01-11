// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_SUMMARY_OPS_INTERNAL_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_SUMMARY_OPS_INTERNAL_H_

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

/// @defgroup summary_ops_internal Summary Ops Internal
/// @{

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * the created `Operation`
class CloseSummaryWriter {
 public:
  CloseSummaryWriter(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   writer);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * the created `Operation`
class CreateSummaryDbWriter {
 public:
  CreateSummaryDbWriter(const ::tensorflow::Scope& scope, ::tensorflow::Input
                      writer, ::tensorflow::Input db_uri, ::tensorflow::Input
                      experiment_name, ::tensorflow::Input run_name,
                      ::tensorflow::Input user_name);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * the created `Operation`
class CreateSummaryFileWriter {
 public:
  CreateSummaryFileWriter(const ::tensorflow::Scope& scope, ::tensorflow::Input
                        writer, ::tensorflow::Input logdir, ::tensorflow::Input
                        max_queue, ::tensorflow::Input flush_millis,
                        ::tensorflow::Input filename_suffix);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * the created `Operation`
class FlushSummaryWriter {
 public:
  FlushSummaryWriter(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   writer);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * the created `Operation`
class ImportEvent {
 public:
  ImportEvent(const ::tensorflow::Scope& scope, ::tensorflow::Input writer,
            ::tensorflow::Input event);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The writer tensor.
class SummaryWriter {
 public:
  /// Optional attribute setters for SummaryWriter
  struct Attrs {
    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs SharedName(StringPiece x) {
      Attrs ret = *this;
      ret.shared_name_ = x;
      return ret;
    }

    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs Container(StringPiece x) {
      Attrs ret = *this;
      ret.container_ = x;
      return ret;
    }

    StringPiece shared_name_ = "";
    StringPiece container_ = "";
  };
  SummaryWriter(const ::tensorflow::Scope& scope);
  SummaryWriter(const ::tensorflow::Scope& scope, const SummaryWriter::Attrs&
              attrs);
  operator ::tensorflow::Output() const { return writer; }
  operator ::tensorflow::Input() const { return writer; }
  ::tensorflow::Node* node() const { return writer.node(); }

  static Attrs SharedName(StringPiece x) {
    return Attrs().SharedName(x);
  }
  static Attrs Container(StringPiece x) {
    return Attrs().Container(x);
  }

  ::tensorflow::Output writer;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * the created `Operation`
class WriteAudioSummary {
 public:
  /// Optional attribute setters for WriteAudioSummary
  struct Attrs {
    /// Defaults to 3
    TF_MUST_USE_RESULT Attrs MaxOutputs(int64 x) {
      Attrs ret = *this;
      ret.max_outputs_ = x;
      return ret;
    }

    int64 max_outputs_ = 3;
  };
  WriteAudioSummary(const ::tensorflow::Scope& scope, ::tensorflow::Input writer,
                  ::tensorflow::Input step, ::tensorflow::Input tag,
                  ::tensorflow::Input tensor, ::tensorflow::Input sample_rate);
  WriteAudioSummary(const ::tensorflow::Scope& scope, ::tensorflow::Input writer,
                  ::tensorflow::Input step, ::tensorflow::Input tag,
                  ::tensorflow::Input tensor, ::tensorflow::Input sample_rate,
                  const WriteAudioSummary::Attrs& attrs);
  operator ::tensorflow::Operation() const { return operation; }

  static Attrs MaxOutputs(int64 x) {
    return Attrs().MaxOutputs(x);
  }

  Operation operation;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * the created `Operation`
class WriteGraphSummary {
 public:
  WriteGraphSummary(const ::tensorflow::Scope& scope, ::tensorflow::Input writer,
                  ::tensorflow::Input step, ::tensorflow::Input tensor);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * the created `Operation`
class WriteHistogramSummary {
 public:
  WriteHistogramSummary(const ::tensorflow::Scope& scope, ::tensorflow::Input
                      writer, ::tensorflow::Input step, ::tensorflow::Input
                      tag, ::tensorflow::Input values);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * the created `Operation`
class WriteImageSummary {
 public:
  /// Optional attribute setters for WriteImageSummary
  struct Attrs {
    /// Defaults to 3
    TF_MUST_USE_RESULT Attrs MaxImages(int64 x) {
      Attrs ret = *this;
      ret.max_images_ = x;
      return ret;
    }

    int64 max_images_ = 3;
  };
  WriteImageSummary(const ::tensorflow::Scope& scope, ::tensorflow::Input writer,
                  ::tensorflow::Input step, ::tensorflow::Input tag,
                  ::tensorflow::Input tensor, ::tensorflow::Input bad_color);
  WriteImageSummary(const ::tensorflow::Scope& scope, ::tensorflow::Input writer,
                  ::tensorflow::Input step, ::tensorflow::Input tag,
                  ::tensorflow::Input tensor, ::tensorflow::Input bad_color,
                  const WriteImageSummary::Attrs& attrs);
  operator ::tensorflow::Operation() const { return operation; }

  static Attrs MaxImages(int64 x) {
    return Attrs().MaxImages(x);
  }

  Operation operation;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * the created `Operation`
class WriteScalarSummary {
 public:
  WriteScalarSummary(const ::tensorflow::Scope& scope, ::tensorflow::Input
                   writer, ::tensorflow::Input step, ::tensorflow::Input tag,
                   ::tensorflow::Input value);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// TODO: add doc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * the created `Operation`
class WriteSummary {
 public:
  WriteSummary(const ::tensorflow::Scope& scope, ::tensorflow::Input writer,
             ::tensorflow::Input step, ::tensorflow::Input tensor,
             ::tensorflow::Input tag, ::tensorflow::Input summary_metadata);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

}  // namespace internal
}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_SUMMARY_OPS_INTERNAL_H_
