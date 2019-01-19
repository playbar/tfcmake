// This file is MACHINE GENERATED! Do not edit.


#include "tensorflow/cc/ops/const_op.h"
#include "tensorflow/cc/ops/rpc_ops.h"

namespace tensorflow {
namespace ops {

Rpc::Rpc(const ::tensorflow::Scope& scope, ::tensorflow::Input address,
         ::tensorflow::Input method, ::tensorflow::Input request, const
         Rpc::Attrs& attrs) {
  if (!scope.ok()) return;
  auto _address = ::tensorflow::ops::AsNodeOut(scope, address);
  if (!scope.ok()) return;
  auto _method = ::tensorflow::ops::AsNodeOut(scope, method);
  if (!scope.ok()) return;
  auto _request = ::tensorflow::ops::AsNodeOut(scope, request);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("Rpc");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "Rpc")
                     .Input(_address)
                     .Input(_method)
                     .Input(_request)
                     .Attr("protocol", attrs.protocol_)
                     .Attr("fail_fast", attrs.fail_fast_)
                     .Attr("timeout_in_ms", attrs.timeout_in_ms_)
  ;
  scope.UpdateBuilder(&builder);
  scope.UpdateStatus(builder.Finalize(scope.graph(), &ret));
  if (!scope.ok()) return;
  scope.UpdateStatus(scope.DoShapeInference(ret));
  this->response = Output(ret, 0);
}

Rpc::Rpc(const ::tensorflow::Scope& scope, ::tensorflow::Input address,
         ::tensorflow::Input method, ::tensorflow::Input request)
  : Rpc(scope, address, method, request, Rpc::Attrs()) {}

TryRpc::TryRpc(const ::tensorflow::Scope& scope, ::tensorflow::Input address,
               ::tensorflow::Input method, ::tensorflow::Input request, const
               TryRpc::Attrs& attrs) {
  if (!scope.ok()) return;
  auto _address = ::tensorflow::ops::AsNodeOut(scope, address);
  if (!scope.ok()) return;
  auto _method = ::tensorflow::ops::AsNodeOut(scope, method);
  if (!scope.ok()) return;
  auto _request = ::tensorflow::ops::AsNodeOut(scope, request);
  if (!scope.ok()) return;
  ::tensorflow::Node* ret;
  const auto unique_name = scope.GetUniqueNameForOp("TryRpc");
  auto builder = ::tensorflow::NodeBuilder(unique_name, "TryRpc")
                     .Input(_address)
                     .Input(_method)
                     .Input(_request)
                     .Attr("protocol", attrs.protocol_)
                     .Attr("fail_fast", attrs.fail_fast_)
                     .Attr("timeout_in_ms", attrs.timeout_in_ms_)
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

  this->response = Output(ret, _outputs_range["response"].first);
  this->status_code = Output(ret, _outputs_range["status_code"].first);
  this->status_message = Output(ret, _outputs_range["status_message"].first);
}

TryRpc::TryRpc(const ::tensorflow::Scope& scope, ::tensorflow::Input address,
               ::tensorflow::Input method, ::tensorflow::Input request)
  : TryRpc(scope, address, method, request, TryRpc::Attrs()) {}

/// @}

}  // namespace ops
}  // namespace tensorflow
