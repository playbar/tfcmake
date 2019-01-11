// This file is MACHINE GENERATED! Do not edit.


#include "tensorflow/cc/ops/const_op.h"
#include "/mywork/github/tfcmake/cmake-build-debug/tensorflow/cc/ops/functional_ops.h"

namespace tensorflow {
namespace ops {

For::For(const ::tensorflow::Scope& scope, ::tensorflow::Input start,
         ::tensorflow::Input limit, ::tensorflow::Input delta,
         ::tensorflow::InputList input, const NameAttrList& body) {
  if (!scope.ok()) return;
  auto _start = ::tensorflow::ops::AsNodeOut(scope, start);
  if (!scope.ok()) return;
  auto _limit = ::tensorflow::ops::AsNodeOut(scope, limit);
  if (!scope.ok()) return;
  auto _delta = ::tensorflow::ops::AsNodeOut(scope, delta);
  if (!scope.ok()) return;
  auto _input = ::tensorflow::ops::AsNodeOutList(scope, input);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("For");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "For")
                     .Input(_start)
                     .Input(_limit)
                     .Input(_delta)
                     .Input(_input)
                     .Attr("body", body)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  for (int32 i = 0; i < ret->num_outputs(); ++i)
    this->output.push_back(Output(ret, i));
}

If::If(const ::tensorflow::Scope& scope, ::tensorflow::Input cond,
       ::tensorflow::InputList input, const DataTypeSlice& Tout, const
       NameAttrList& then_branch, const NameAttrList& else_branch) {
  if (!scope.ok()) return;
  auto _cond = ::tensorflow::ops::AsNodeOut(scope, cond);
  if (!scope.ok()) return;
  auto _input = ::tensorflow::ops::AsNodeOutList(scope, input);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("If");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "If")
                     .Input(_cond)
                     .Input(_input)
                     .Attr("Tout", Tout)
                     .Attr("then_branch", then_branch)
                     .Attr("else_branch", else_branch)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  for (int32 i = 0; i < ret->num_outputs(); ++i)
    this->output.push_back(Output(ret, i));
}

PartitionedCall::PartitionedCall(const ::tensorflow::Scope& scope,
                                 ::tensorflow::InputList args, const
                                 DataTypeSlice& Tout, const NameAttrList& f) {
  if (!scope.ok()) return;
  auto _args = ::tensorflow::ops::AsNodeOutList(scope, args);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("PartitionedCall");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "PartitionedCall")
                     .Input(_args)
                     .Attr("Tout", Tout)
                     .Attr("f", f)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  for (int32 i = 0; i < ret->num_outputs(); ++i)
    this->output.push_back(Output(ret, i));
}

RemoteCall::RemoteCall(const ::tensorflow::Scope& scope, ::tensorflow::Input
                       target, ::tensorflow::InputList args, const
                       DataTypeSlice& Tout, const NameAttrList& f) {
  if (!scope.ok()) return;
  auto _target = ::tensorflow::ops::AsNodeOut(scope, target);
  if (!scope.ok()) return;
  auto _args = ::tensorflow::ops::AsNodeOutList(scope, args);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("RemoteCall");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "RemoteCall")
                     .Input(_target)
                     .Input(_args)
                     .Attr("Tout", Tout)
                     .Attr("f", f)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  for (int32 i = 0; i < ret->num_outputs(); ++i)
    this->output.push_back(Output(ret, i));
}

SymbolicGradient::SymbolicGradient(const ::tensorflow::Scope& scope,
                                   ::tensorflow::InputList input, const
                                   DataTypeSlice& Tout, const NameAttrList& f) {
  if (!scope.ok()) return;
  auto _input = ::tensorflow::ops::AsNodeOutList(scope, input);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("SymbolicGradient");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "SymbolicGradient")
                     .Input(_input)
                     .Attr("Tout", Tout)
                     .Attr("f", f)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  for (int32 i = 0; i < ret->num_outputs(); ++i)
    this->output.push_back(Output(ret, i));
}

While::While(const ::tensorflow::Scope& scope, ::tensorflow::InputList input,
             const NameAttrList& cond, const NameAttrList& body) {
  if (!scope.ok()) return;
  auto _input = ::tensorflow::ops::AsNodeOutList(scope, input);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("While");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "While")
                     .Input(_input)
                     .Attr("cond", cond)
                     .Attr("body", body)
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
