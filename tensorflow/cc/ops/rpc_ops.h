// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_RPC_OPS_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_RPC_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

/// @defgroup rpc_ops Rpc Ops
/// @{

/// Perform batches of RPC requests.
///
/// This op asynchronously performs either a single RPC request, or a batch
/// of requests.  RPC requests are defined by three main parameters:
///
///   - `address` (the host+port or BNS address of the request)
///   - `method` (the RPC method name for the request)
///   - `request` (the serialized proto string, or vector of strings,
///      of the RPC request argument).
///
/// For example, if you have an RPC service running on port localhost:2345,
/// and its interface is configured with the following proto declaration:
///
/// ```
/// service MyService {
///   rpc MyMethod(MyRequestProto) returns (MyResponseProto) {
///   }
/// };
/// ```
///
/// then call this op with arguments:
///
/// ```
/// address = "localhost:2345"
/// method = "MyService/MyMethod"
/// ```
///
/// The `request` tensor is a string tensor representing serialized `MyRequestProto`
/// strings; and the output string tensor `response` will have the same shape
/// and contain (upon successful completion) corresponding serialized
/// `MyResponseProto` strings.
///
/// For example, to send a single, empty, `MyRequestProto`, call
/// this op with `request = ""`.  To send 5 **parallel** empty requests,
/// call this op with `request = ["", "", "", "", ""]`.
///
/// More generally, one can create a batch of `MyRequestProto` serialized protos
/// from regular batched tensors using the `encode_proto` op, and convert
/// the response `MyResponseProto` serialized protos to batched tensors
/// using the `decode_proto` op.
///
/// **NOTE** Working with serialized proto strings is faster than instantiating
/// actual proto objects in memory, so no performance degradation is expected
/// compared to writing custom kernels for this workflow.
///
/// If the connection fails or the remote worker returns an error
/// status, the op reraises this exception locally.
///
/// See the `TryRpc` op if you prefer to handle RPC failures manually in the graph.
///
/// Arguments:
/// * scope: A Scope object
/// * address: `0-D` or `1-D`.  The address (i.e. host_name:port) of the RPC server.
/// If this tensor has more than 1 element, then multiple parallel rpc requests
/// are sent.  This argument broadcasts with `method` and `request`.
/// * method: `0-D` or `1-D`.  The method address on the RPC server.
/// If this tensor has more than 1 element, then multiple parallel rpc requests
/// are sent.  This argument broadcasts with `address` and `request`.
/// * request: `0-D` or `1-D`.  Serialized proto strings: the rpc request argument.
/// If this tensor has more than 1 element, then multiple parallel rpc requests
/// are sent.  This argument broadcasts with `address` and `method`.
///
/// Optional attributes (see `Attrs`):
/// * protocol: RPC protocol to use.  Empty string means use the default protocol.
/// Options include 'grpc'.
/// * fail_fast: `boolean`. If `true` (default), then failures to connect
/// (i.e., the server does not immediately respond) cause an RPC failure.
/// * timeout_in_ms: `int`. If `0` (default), then the kernel will run the RPC
/// request and only time out if the RPC deadline passes or the session times out.
/// If this value is greater than `0`, then the op will raise an exception if
/// the RPC takes longer than `timeout_in_ms`.
///
/// Returns:
/// * `Output`: Same shape as `request`. Serialized proto strings: the rpc responses.
class Rpc {
 public:
  /// Optional attribute setters for Rpc
  struct Attrs {
    /// RPC protocol to use.  Empty string means use the default protocol.
    /// Options include 'grpc'.
    ///
    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs Protocol(StringPiece x) {
      Attrs ret = *this;
      ret.protocol_ = x;
      return ret;
    }

    /// `boolean`. If `true` (default), then failures to connect
    /// (i.e., the server does not immediately respond) cause an RPC failure.
    ///
    /// Defaults to true
    TF_MUST_USE_RESULT Attrs FailFast(bool x) {
      Attrs ret = *this;
      ret.fail_fast_ = x;
      return ret;
    }

    /// `int`. If `0` (default), then the kernel will run the RPC
    /// request and only time out if the RPC deadline passes or the session times out.
    /// If this value is greater than `0`, then the op will raise an exception if
    /// the RPC takes longer than `timeout_in_ms`.
    ///
    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs TimeoutInMs(int64 x) {
      Attrs ret = *this;
      ret.timeout_in_ms_ = x;
      return ret;
    }

    StringPiece protocol_ = "";
    bool fail_fast_ = true;
    int64 timeout_in_ms_ = 0;
  };
  Rpc(const ::tensorflow::Scope& scope, ::tensorflow::Input address,
    ::tensorflow::Input method, ::tensorflow::Input request);
  Rpc(const ::tensorflow::Scope& scope, ::tensorflow::Input address,
    ::tensorflow::Input method, ::tensorflow::Input request, const Rpc::Attrs&
    attrs);
  operator ::tensorflow::Output() const { return response; }
  operator ::tensorflow::Input() const { return response; }
  ::tensorflow::Node* node() const { return response.node(); }

  static Attrs Protocol(StringPiece x) {
    return Attrs().Protocol(x);
  }
  static Attrs FailFast(bool x) {
    return Attrs().FailFast(x);
  }
  static Attrs TimeoutInMs(int64 x) {
    return Attrs().TimeoutInMs(x);
  }

  ::tensorflow::Output response;
};

/// Perform batches of RPC requests.
///
/// This op asynchronously performs either a single RPC request, or a batch
/// of requests.  RPC requests are defined by three main parameters:
///
///   - `address` (the host+port or BNS address of the request)
///   - `method` (the method name for the request)
///   - `request` (the serialized proto string, or vector of strings,
///      of the RPC request argument).
///
/// For example, if you have an RPC service running on port localhost:2345,
/// and its interface is configured with the following proto declaration:
///
/// ```
/// service MyService {
///   rpc MyMethod(MyRequestProto) returns (MyResponseProto) {
///   }
/// };
/// ```
///
/// then call this op with arguments:
///
/// ```
/// address = "localhost:2345"
/// method = "MyService/MyMethod"
/// ```
///
/// The `request` tensor is a string tensor representing serialized `MyRequestProto`
/// strings; and the output string tensor `response` will have the same shape
/// and contain (upon successful completion) corresponding serialized
/// `MyResponseProto` strings.
///
/// For example, to send a single, empty, `MyRequestProto`, call
/// this op with `request = ""`.  To send 5 **parallel** empty requests,
/// call this op with `request = ["", "", "", "", ""]`.
///
/// More generally, one can create a batch of `MyRequestProto` serialized protos
/// from regular batched tensors using the `encode_proto` op, and convert
/// the response `MyResponseProto` serialized protos to batched tensors
/// using the `decode_proto` op.
///
/// **NOTE** Working with serialized proto strings is faster than instantiating
/// actual proto objects in memory, so no performance degradation is expected
/// compared to writing custom kernels for this workflow.
///
/// Unlike the standard `Rpc` op, if the connection fails or the remote worker
/// returns an error status, this op does **not** reraise the exception.
/// Instead, the `status_code` and `status_message` entry for the corresponding RPC
/// call is set with the error returned from the RPC call.  The `response` tensor
/// will contain valid response values for those minibatch entries whose RPCs did
/// not fail; the rest of the entries will have empty strings.
///
/// Arguments:
/// * scope: A Scope object
/// * address: `0-D` or `1-D`.  The address (i.e. host_name:port) of the RPC server.
/// If this tensor has more than 1 element, then multiple parallel rpc requests
/// are sent.  This argument broadcasts with `method` and `request`.
/// * method: `0-D` or `1-D`.  The method address on the RPC server.
/// If this tensor has more than 1 element, then multiple parallel rpc requests
/// are sent.  This argument broadcasts with `address` and `request`.
/// * request: `0-D` or `1-D`.  Serialized proto strings: the rpc request argument.
/// If this tensor has more than 1 element, then multiple parallel rpc requests
/// are sent.  This argument broadcasts with `address` and `method`.
///
/// Optional attributes (see `Attrs`):
/// * protocol: RPC protocol to use.  Empty string means use the default protocol.
/// Options include 'grpc'.
/// * fail_fast: `boolean`. If `true` (default), then failures to connect
/// (i.e., the server does not immediately respond) cause an RPC failure.
/// * timeout_in_ms: `int`. If `0` (default), then the kernel will run the RPC
/// request and only time out if the RPC deadline passes or the session times out.
/// If this value is greater than `0`, then the op will raise an exception if
/// the RPC takes longer than `timeout_in_ms`.
///
/// Returns:
/// * `Output` response: Same shape as `request`. Serialized proto strings: the rpc responses.
/// * `Output` status_code: Same shape as `request`.  Values correspond to tensorflow Status enum codes.
/// * `Output` status_message: Same shape as `request`.  Values correspond to Status messages
/// returned from the RPC calls.
class TryRpc {
 public:
  /// Optional attribute setters for TryRpc
  struct Attrs {
    /// RPC protocol to use.  Empty string means use the default protocol.
    /// Options include 'grpc'.
    ///
    /// Defaults to ""
    TF_MUST_USE_RESULT Attrs Protocol(StringPiece x) {
      Attrs ret = *this;
      ret.protocol_ = x;
      return ret;
    }

    /// `boolean`. If `true` (default), then failures to connect
    /// (i.e., the server does not immediately respond) cause an RPC failure.
    ///
    /// Defaults to true
    TF_MUST_USE_RESULT Attrs FailFast(bool x) {
      Attrs ret = *this;
      ret.fail_fast_ = x;
      return ret;
    }

    /// `int`. If `0` (default), then the kernel will run the RPC
    /// request and only time out if the RPC deadline passes or the session times out.
    /// If this value is greater than `0`, then the op will raise an exception if
    /// the RPC takes longer than `timeout_in_ms`.
    ///
    /// Defaults to 0
    TF_MUST_USE_RESULT Attrs TimeoutInMs(int64 x) {
      Attrs ret = *this;
      ret.timeout_in_ms_ = x;
      return ret;
    }

    StringPiece protocol_ = "";
    bool fail_fast_ = true;
    int64 timeout_in_ms_ = 0;
  };
  TryRpc(const ::tensorflow::Scope& scope, ::tensorflow::Input address,
       ::tensorflow::Input method, ::tensorflow::Input request);
  TryRpc(const ::tensorflow::Scope& scope, ::tensorflow::Input address,
       ::tensorflow::Input method, ::tensorflow::Input request, const
       TryRpc::Attrs& attrs);

  static Attrs Protocol(StringPiece x) {
    return Attrs().Protocol(x);
  }
  static Attrs FailFast(bool x) {
    return Attrs().FailFast(x);
  }
  static Attrs TimeoutInMs(int64 x) {
    return Attrs().TimeoutInMs(x);
  }

  ::tensorflow::Output response;
  ::tensorflow::Output status_code;
  ::tensorflow::Output status_message;
};

/// @}

}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_RPC_OPS_H_
