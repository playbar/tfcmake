// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_DECODE_PROTO_OPS_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_DECODE_PROTO_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

/// @defgroup decode_proto_ops Decode Proto Ops
/// @{

/// The op extracts fields from a serialized protocol buffers message into tensors.
///
/// The `decode_proto` op extracts fields from a serialized protocol buffers
/// message into tensors.  The fields in `field_names` are decoded and converted
/// to the corresponding `output_types` if possible.
///
/// A `message_type` name must be provided to give context for the field
/// names. The actual message descriptor can be looked up either in the
/// linked-in descriptor pool or a filename provided by the caller using
/// the `descriptor_source` attribute.
///
/// Each output tensor is a dense tensor. This means that it is padded to
/// hold the largest number of repeated elements seen in the input
/// minibatch. (The shape is also padded by one to prevent zero-sized
/// dimensions). The actual repeat counts for each example in the
/// minibatch can be found in the `sizes` output. In many cases the output
/// of `decode_proto` is fed immediately into tf.squeeze if missing values
/// are not a concern. When using tf.squeeze, always pass the squeeze
/// dimension explicitly to avoid surprises.
///
/// For the most part, the mapping between Proto field types and
/// TensorFlow dtypes is straightforward. However, there are a few
/// special cases:
///
/// - A proto field that contains a submessage or group can only be converted
/// to `DT_STRING` (the serialized submessage). This is to reduce the
/// complexity of the API. The resulting string can be used as input
/// to another instance of the decode_proto op.
///
/// - TensorFlow lacks support for unsigned integers. The ops represent uint64
/// types as a `DT_INT64` with the same twos-complement bit pattern
/// (the obvious way). Unsigned int32 values can be represented exactly by
/// specifying type `DT_INT64`, or using twos-complement if the caller
/// specifies `DT_INT32` in the `output_types` attribute.
///
/// The `descriptor_source` attribute selects a source of protocol
/// descriptors to consult when looking up `message_type`. This may be a
/// filename containing a serialized `FileDescriptorSet` message,
/// or the special value `local://`, in which case only descriptors linked
/// into the code will be searched; the filename can be on any filesystem
/// accessible to TensorFlow.
///
/// You can build a `descriptor_source` file using the `--descriptor_set_out`
/// and `--include_imports` options to the protocol compiler `protoc`.
///
/// The `local://` database only covers descriptors linked into the
/// code via C++ libraries, not Python imports. You can link in a proto descriptor
/// by creating a cc_library target with alwayslink=1.
///
/// Both binary and text proto serializations are supported, and can be
/// chosen using the `format` attribute.
///
/// Arguments:
/// * scope: A Scope object
/// * bytes: Tensor of serialized protos with shape `batch_shape`.
/// * message_type: Name of the proto message type to decode.
/// * field_names: List of strings containing proto field names.
/// * output_types: List of TF types to use for the respective field in field_names.
///
/// Optional attributes (see `Attrs`):
/// * descriptor_source: Either the special value `local://` or a path to a file containing
/// a serialized `FileDescriptorSet`.
/// * message_format: Either `binary` or `text`.
/// * sanitize: Whether to sanitize the result or not.
///
/// Returns:
/// * `Output` sizes: Tensor of int32 with shape `[batch_shape, len(field_names)]`.
/// Each entry is the number of values found for the corresponding field.
/// Optional fields may have 0 or 1 values.
/// * `OutputList` values: List of tensors containing values for the corresponding field.
/// `values[i]` has datatype `output_types[i]`
/// and shape `[batch_shape, max(sizes[...,i])]`.
class DecodeProtoV2 {
 public:
  /// Optional attribute setters for DecodeProtoV2
  struct Attrs {
    /// Either the special value `local://` or a path to a file containing
    /// a serialized `FileDescriptorSet`.
    ///
    /// Defaults to "local://"
    TF_MUST_USE_RESULT Attrs DescriptorSource(StringPiece x) {
      Attrs ret = *this;
      ret.descriptor_source_ = x;
      return ret;
    }

    /// Either `binary` or `text`.
    ///
    /// Defaults to "binary"
    TF_MUST_USE_RESULT Attrs MessageFormat(StringPiece x) {
      Attrs ret = *this;
      ret.message_format_ = x;
      return ret;
    }

    /// Whether to sanitize the result or not.
    ///
    /// Defaults to false
    TF_MUST_USE_RESULT Attrs Sanitize(bool x) {
      Attrs ret = *this;
      ret.sanitize_ = x;
      return ret;
    }

    StringPiece descriptor_source_ = "local://";
    StringPiece message_format_ = "binary";
    bool sanitize_ = false;
  };
  DecodeProtoV2(const ::tensorflow::Scope& scope, ::tensorflow::Input bytes,
              StringPiece message_type, const gtl::ArraySlice<string>&
              field_names, const DataTypeSlice& output_types);
  DecodeProtoV2(const ::tensorflow::Scope& scope, ::tensorflow::Input bytes,
              StringPiece message_type, const gtl::ArraySlice<string>&
              field_names, const DataTypeSlice& output_types, const
              DecodeProtoV2::Attrs& attrs);

  static Attrs DescriptorSource(StringPiece x) {
    return Attrs().DescriptorSource(x);
  }
  static Attrs MessageFormat(StringPiece x) {
    return Attrs().MessageFormat(x);
  }
  static Attrs Sanitize(bool x) {
    return Attrs().Sanitize(x);
  }

  ::tensorflow::Output sizes;
  ::tensorflow::OutputList values;
};

/// @}

}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_DECODE_PROTO_OPS_H_
