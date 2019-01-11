// This file is MACHINE GENERATED! Do not edit.

#ifndef _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_SCRIPT_OPS_H_
#define _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_SCRIPT_OPS_H_

// This file is MACHINE GENERATED! Do not edit.

#include "tensorflow/cc/framework/ops.h"
#include "tensorflow/cc/framework/scope.h"
#include "tensorflow/core/framework/tensor.h"
#include "tensorflow/core/framework/tensor_shape.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/gtl/array_slice.h"

namespace tensorflow {
namespace ops {

/// @defgroup script_ops Script Ops
/// @{

/// Eagerly executes a python function to compute func(input)->output. The
///
/// semantics of the input, output, and attributes are the same as those for
/// PyFunc.
///
/// Arguments:
/// * scope: A Scope object
///
/// Returns:
/// * `OutputList`: The output tensor.
class EagerPyFunc {
 public:
  EagerPyFunc(const ::tensorflow::Scope& scope, ::tensorflow::InputList input,
            StringPiece token, const DataTypeSlice& Tout);
  ::tensorflow::Output operator[](size_t index) const { return output[index]; }


  ::tensorflow::OutputList output;
};

/// @}

}  // namespace ops
}  // namespace tensorflow

#endif  // _MYWORK_GITHUB_TFCMAKE_CMAKE_BUILD_DEBUG_TENSORFLOW_CC_OPS_SCRIPT_OPS_H_
