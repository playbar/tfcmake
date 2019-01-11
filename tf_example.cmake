# Copyright 2017 The TensorFlow Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================
set(tf_example_example_srcs
    "${CMAKE_SOURCE_DIR}/example/example.cc"
)

add_executable(tf_example_example
    ${tf_example_example_srcs}
    re2
    $<TARGET_OBJECTS:tf_c>
    $<TARGET_OBJECTS:tf_cc>
    $<TARGET_OBJECTS:tf_core_lib>
    $<TARGET_OBJECTS:tf_core_cpu>
    $<TARGET_OBJECTS:tf_core_framework>
    $<TARGET_OBJECTS:tf_core_kernels>
    $<TARGET_OBJECTS:tf_cc_framework>
    $<TARGET_OBJECTS:tf_cc_ops>
    $<TARGET_OBJECTS:tf_core_profiler>
    $<TARGET_OBJECTS:tf_cc_while_loop>
    $<TARGET_OBJECTS:tf_core_kernels>
    $<TARGET_OBJECTS:tf_core_ops>
    $<TARGET_OBJECTS:tf_core_distributed_runtime>
    $<TARGET_OBJECTS:tf_core_direct_session>
    $<$<BOOL:${tensorflow_ENABLE_GPU}>:$<TARGET_OBJECTS:tf_stream_executor>>
)

target_link_libraries(tf_example_example PUBLIC
    tf_protos_cc
    ${tf_core_gpu_kernels_lib}
    ${tensorflow_EXTERNAL_LIBRARIES}
)

###########

set(tf_example_trainmodel_srcs
        "${CMAKE_SOURCE_DIR}/example/train_model.cc"
        )

add_executable(tf_example_trainmodel
        ${tf_example_trainmodel_srcs}
        $<TARGET_OBJECTS:tf_core_lib>
        $<TARGET_OBJECTS:tf_core_cpu>
        $<TARGET_OBJECTS:tf_core_framework>
        $<TARGET_OBJECTS:tf_core_kernels>
        $<TARGET_OBJECTS:tf_cc_framework>
        $<TARGET_OBJECTS:tf_cc_ops>
        $<TARGET_OBJECTS:tf_core_ops>
        $<TARGET_OBJECTS:tf_core_direct_session>
        $<$<BOOL:${tensorflow_ENABLE_GPU}>:$<TARGET_OBJECTS:tf_stream_executor>>
        )

target_link_libraries(tf_example_trainmodel PUBLIC
        tf_protos_cc
        ${tf_core_gpu_kernels_lib}
        ${tensorflow_EXTERNAL_LIBRARIES}
        )
