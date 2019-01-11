// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_USER_OPS_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_USER_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

/// @defgroup user_ops User Ops
/// @{

/// Output a fact about factorials.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `Output`: The fact tensor.
class Fact {
 public:
  Fact(const ::tensorflow::Scope& scope);
  operator ::tensorflow::Output() const { return fact; }
  operator ::tensorflow::Input() const { return fact; }
  ::tensorflow::Node* node() const { return fact.node(); }

  ::tensorflow::Output fact;
};

/// @}

}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_USER_OPS_H_
