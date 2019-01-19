// This file is MACHINE GENERATED! Do not edit.


#include "tensorflow/cc/ops/const_op.h"
#include "tensorflow/cc/ops/script_ops.h"

namespace tensorflow {
namespace ops {

EagerPyFunc::EagerPyFunc(const ::tensorflow::Scope& scope,
                         ::tensorflow::InputList input, StringPiece token,
                         const DataTypeSlice& Tout) {
  if (!scope.ok()) return;
  auto _input = ::tensorflow::ops::AsNodeOutList(scope, input);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("EagerPyFunc");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "EagerPyFunc")
                     .Input(_input)
                     .Attr("token", token)
                     .Attr("Tout", Tout)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  for (int32 i = 0; i < ret->num_outputs(); ++i)
    this->output.push_back(Output(ret, i));
}

/// @}

}  // namespace ops
}  // namespace tensorflow
