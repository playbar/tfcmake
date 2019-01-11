// This file is MACHINE GENERATED! Do not edit.


#include "tensorflow/cc/ops/const_op.h"
#include "/mywork/github/tfcmake/cmake-build-debug/tensorflow/cc/ops/encode_proto_ops.h"

namespace tensorflow {
namespace ops {

EncodeProto::EncodeProto(const ::tensorflow::Scope& scope, ::tensorflow::Input
                         sizes, ::tensorflow::InputList values, const
                         gtl::ArraySlice<string>& field_names, StringPiece
                         message_type, const EncodeProto::Attrs& attrs) {
  if (!scope.ok()) return;
  auto _sizes = ::tensorflow::ops::AsNodeOut(scope, sizes);
  if (!scope.ok()) return;
  auto _values = ::tensorflow::ops::AsNodeOutList(scope, values);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("EncodeProto");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "EncodeProto")
                     .Input(_sizes)
                     .Input(_values)
                     .Attr("field_names", field_names)
                     .Attr("message_type", message_type)
                     .Attr("descriptor_source", attrs.descriptor_source_)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->bytes = Output(ret, 0);
}

EncodeProto::EncodeProto(const ::tensorflow::Scope& scope, ::tensorflow::Input
                         sizes, ::tensorflow::InputList values, const
                         gtl::ArraySlice<string>& field_names, StringPiece
                         message_type)
  : EncodeProto(scope, sizes, values, field_names, message_type, EncodeProto::Attrs()) {}

/// @}

}  // namespace ops
}  // namespace tensorflow
