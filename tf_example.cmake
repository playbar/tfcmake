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

set(tf_example_image_classify_srcs
        "${CMAKE_SOURCE_DIR}/example/image_classify/dataset.cc"
        "${CMAKE_SOURCE_DIR}/example/image_classify/image_classifier.cc"
        "${CMAKE_SOURCE_DIR}/example/image_classify/main.cc"
        )

add_executable(tf_example_image_classify
        ${tf_example_image_classify_srcs}
        )

target_link_libraries(tf_example_image_classify PUBLIC
        tensorflow
#        tf_cc
#        tf_cc_ops
        #        ${tensorflow_EXTERNAL_LIBRARIES}
        )

target_include_directories(tf_example_image_classify PUBLIC
        ${CMAKE_SOURCE_DIR}/example/image_classify
)

################
set(tf_example_linerpb_srcs
        "${CMAKE_SOURCE_DIR}/example/linerpb/ann_model_loader.cpp"
        "${CMAKE_SOURCE_DIR}/example/linerpb/linerpb.cpp"
        )

add_executable(tf_example_linerpb
        ${tf_example_linerpb_srcs}
        )

target_link_libraries(tf_example_linerpb PUBLIC
        tensorflow
        )

target_include_directories(tf_example_linerpb PUBLIC
        ${CMAKE_SOURCE_DIR}/example/linerpb
        )

################

set(tf_example_simple_model_srcs
        "${CMAKE_SOURCE_DIR}/example/predictor/simple_model.cc"
        )

add_executable(tf_example_simple_model
        ${tf_example_simple_model_srcs}
        )

target_link_libraries(tf_example_simple_model PUBLIC
        tensorflow
        )

target_include_directories(tf_example_simple_model PUBLIC
        ${CMAKE_SOURCE_DIR}/example/predictor
        )

################
set(tf_example_deep_model_srcs
        "${CMAKE_SOURCE_DIR}/example/predictor/deep_model.cc"
        )

add_executable(tf_example_deep_model
        ${tf_example_deep_model_srcs}
        )

target_link_libraries(tf_example_deep_model PUBLIC
        tensorflow
        )

target_include_directories(tf_example_deep_model PUBLIC
        ${CMAKE_SOURCE_DIR}/example/predictor
        )

################
set(tf_example_tutorial_srcs
        "${CMAKE_SOURCE_DIR}/example/tutorial/ann_model_loader.cpp"
        "${CMAKE_SOURCE_DIR}/example/tutorial/main.cpp"
        )

add_executable(tf_example_tutorial
        ${tf_example_tutorial_srcs}
        )

target_link_libraries(tf_example_tutorial PUBLIC
        tensorflow
        )

target_include_directories(tf_example_tutorial PUBLIC
        ${CMAKE_SOURCE_DIR}/example/tutorial
        )

############
set(tf_example_dnnmodel_srcs
        "${CMAKE_SOURCE_DIR}/example/dnnmodel.cc"
        )

add_executable(tf_example_dnnmodel
        ${tf_example_dnnmodel_srcs}
        )

target_link_libraries(tf_example_dnnmodel PUBLIC
        tensorflow
#        tf_cc
#        tf_cc_ops
#        tf_cc_framework
#        tf_core_framework
        #        ${tensorflow_EXTERNAL_LIBRARIES}
        )

##############

set(tf_example_example_srcs
        "${CMAKE_SOURCE_DIR}/example/example.cc"
        )

add_executable(tf_example_example
        ${tf_example_example_srcs}
        )

target_link_libraries(tf_example_example PUBLIC
        tensorflow
        )

#set(tf_example_example_srcs
#    "${CMAKE_SOURCE_DIR}/example/example.cc"
#)
#
#add_executable(tf_example_example
#    ${tf_example_example_srcs}
##    $<TARGET_OBJECTS:tf_protos_cc>
#    $<TARGET_OBJECTS:tf_c>
#    $<TARGET_OBJECTS:tf_cc>
#    $<TARGET_OBJECTS:tf_core_lib>
#    $<TARGET_OBJECTS:tf_core_cpu>
#    $<TARGET_OBJECTS:tf_core_framework>
#    $<TARGET_OBJECTS:tf_core_kernels>
#    $<TARGET_OBJECTS:tf_cc_framework>
#    $<TARGET_OBJECTS:tf_cc_ops>
#    $<TARGET_OBJECTS:tf_core_profiler>
#    $<TARGET_OBJECTS:tf_cc_while_loop>
#    $<TARGET_OBJECTS:tf_core_ops>
#    $<TARGET_OBJECTS:tf_core_distributed_runtime>
#    $<TARGET_OBJECTS:tf_core_direct_session>
#)
#
#target_link_libraries(tf_example_example PUBLIC
#    tf_protos_cc
##    tf_c
##    tf_cc
##    tf_core_framework
##    tf_cc_framework
##    tf_core_lib
##    tf_cc_ops
##    tf_core_profiler
#    re2
#    ${tf_core_kernels}
#    ${tf_core_gpu_kernels_lib}
#    ${tensorflow_EXTERNAL_LIBRARIES}
#)

##########

set(tf_example_trainmodel_srcs
        "${CMAKE_SOURCE_DIR}/example/train_model.cc"
        )

add_executable(tf_example_trainmodel
        ${tf_example_trainmodel_srcs}
        )

target_link_libraries(tf_example_trainmodel PUBLIC
        tensorflow
#        tf_cc
#        tf_cc_ops
        )
