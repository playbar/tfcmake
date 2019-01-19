// This file is MACHINE GENERATED! Do not edit.


#include "tensorflow/cc/ops/const_op.h"
#include "tensorflow/cc/ops/decode_proto_ops.h"

namespace tensorflow {
namespace ops {

DecodeProtoV2::DecodeProtoV2(const ::tensorflow::Scope& scope,
                             ::tensorflow::Input bytes, StringPiece
                             message_type, const gtl::ArraySlice<string>&
                             field_names, const DataTypeSlice& output_types,
                             const DecodeProtoV2::Attrs& attrs) {
  if (!scope.ok()) return;
  auto _bytes = ::tensorflow::ops::AsNodeOut(scope, bytes);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("DecodeProtoV2");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "DecodeProtoV2")
                     .Input(_bytes)
                     .Attr("message_type", message_type)
                     .Attr("field_names", field_names)
                     .Attr("output_types", output_types)
                     .Attr("descriptor_source", attrs.descriptor_source_)
                     .Attr("message_format", attrs.message_format_)
                     .Attr("sanitize", attrs.sanitize_)
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

  this->sizes = Output(ret, _outputs_range["sizes"].first);
  for (int32 i = _outputs_range["values"].first; i < _outputs_range["values"].second; ++i)
    this->values.push_back(Output(ret, i));
}

DecodeProtoV2::DecodeProtoV2(const ::tensorflow::Scope& scope,
                             ::tensorflow::Input bytes, StringPiece
                             message_type, const gtl::ArraySlice<string>&
                             field_names, const DataTypeSlice& output_types)
  : DecodeProtoV2(scope, bytes, message_type, field_names, output_types, DecodeProtoV2::Attrs()) {}

/// @}

}  // namespace ops
}  // namespace tensorflow
