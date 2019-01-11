// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_NO_OP_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_NO_OP_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

/// @defgroup no_op No Op
/// @{

/// Does nothing. Only useful as a placeholder for control edges.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * the created `Operation`
class NoOp {
 public:
  NoOp(const ::tensorflow::Scope& scope);
  operator ::tensorflow::Operation() const { return operation; }

  Operation operation;
};

/// @}

}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_NO_OP_H_
