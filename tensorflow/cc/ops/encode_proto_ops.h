// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_ENCODE_PROTO_OPS_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_ENCODE_PROTO_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

/// @defgroup encode_proto_ops Encode Proto Ops
/// @{

/// The op serializes protobuf messages provided in the input tensors.
///
/// The types of the tensors in `values` must match the schema for the
/// fields specified in `field_names`. All the tensors in `values` must
/// have a common shape prefix, *batch_shape*.
///
/// The `sizes` tensor specifies repeat counts for each field.  The repeat
/// count (last dimension) of a each tensor in `values` must be greater
/// than or equal to corresponding repeat count in `sizes`.
///
/// A `message_type` name must be provided to give context for the field
/// names. The actual message descriptor can be looked up either in the
/// linked-in descriptor pool or a filename provided by the caller using
/// the `descriptor_source` attribute.
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
/// There are a few special cases in the value mapping:
///
/// Submessage and group fields must be pre-serialized as TensorFlow strings.
///
/// TensorFlow lacks support for unsigned int64s, so they must be
/// represented as `tf.int64` with the same twos-complement bit pattern
/// (the obvious way).
///
/// Unsigned int32 values can be represented exactly with `tf.int64`, or
/// with sign wrapping if the input is of type `tf.int32`.
///
/// Arguments:
/// * scope: A Scope object
/// * sizes: Tensor of int32 with shape `[batch_shape, len(field_names)]`.
/// * values: List of tensors containing values for the corresponding field.
/// * field_names: List of strings containing proto field names.
/// * message_type: Name of the proto message type to decode.
///
/// Returns:
/// * `Output`: Tensor of serialized protos with shape `batch_shape`.
class EncodeProto {
 public:
  /// Optional attribute setters for EncodeProto
  struct Attrs {
    /// Defaults to "local://"
    TF_MUST_USE_RESULT Attrs DescriptorSource(StringPiece x) {
      Attrs ret = *this;
      ret.descriptor_source_ = x;
      return ret;
    }

    StringPiece descriptor_source_ = "local://";
  };
  EncodeProto(const ::tensorflow::Scope& scope, ::tensorflow::Input sizes,
            ::tensorflow::InputList values, const gtl::ArraySlice<string>&
            field_names, StringPiece message_type);
  EncodeProto(const ::tensorflow::Scope& scope, ::tensorflow::Input sizes,
            ::tensorflow::InputList values, const gtl::ArraySlice<string>&
            field_names, StringPiece message_type, const EncodeProto::Attrs&
            attrs);
  operator ::tensorflow::Output() const { return bytes; }
  operator ::tensorflow::Input() const { return bytes; }
  ::tensorflow::Node* node() const { return bytes.node(); }

  static Attrs DescriptorSource(StringPiece x) {
    return Attrs().DescriptorSource(x);
  }

  ::tensorflow::Output bytes;
};

/// @}

}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_ENCODE_PROTO_OPS_H_
