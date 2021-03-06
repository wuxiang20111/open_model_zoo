// Copyright (C) 2018 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once
#include <gflags/gflags.h>
#include <functional>
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <time.h>
#include <limits>
#include <chrono>

#include <format_reader_ptr.h>
#include <inference_engine.hpp>

#include "../common/samples/common.hpp"

/// @brief message for help argument
static const char help_message[] = "Print a usage message.";

/// @brief message for images argument
static const char image_message[] = "Required. Path to an .bmp image.";

/// @brief message for plugin_path argument
static const char plugin_path_message[] = "Path to a plugin folder.";

/// @brief message for model argument
static const char model_message[] = "Required. Path to an .xml file with a trained model.";

/// @brief message for assigning cnn calculation to device
static const char target_device_message[] = "Specify the target device to infer on; CPU, GPU, FPGA or MYRIAD is acceptable. " \
"The demo will look for a suitable plugin for a specified device.";

/// @brief message for performance counters
static const char performance_counter_message[] = "Enables per-layer performance report";

/// @brief message for iterations count
static const char iterations_count_message[] = "Number of iterations (default 1)";

/// @brief message for clDNN custom kernels desc
static const char custom_cldnn_message[] = "Required for clDNN (GPU)-targeted custom kernels. "\
"Absolute path to the xml file with the kernels desc.";

/// @brief message for user library argument
static const char custom_cpu_library_message[] = "Required for MKLDNN (CPU)-targeted custom layers. " \
"Absolute path to a shared library with the kernels impl.";

/// @brief message for bbox layer name argument
static const char bbox_layer_name_message[] = "The name of output box prediction layer (default: bbox_pred)";
/// @brief message for proposal layer name argument
static const char proposal_layer_name_message[] = "The name of output proposal layer (default: proposal)";
/// @brief message for prob layer name argument
static const char prob_layer_name_message[] = "The name of output probability layer (default: cls_prob)";

/// @brief message for plugin messages
static const char plugin_message[] = "Enables messages from a plugin";

/// @brief Define flag for showing help message <br>
DEFINE_bool(h, false, help_message);

/// @brief Define parameter for set image file <br>
/// It is a required parameter
DEFINE_string(i, "", image_message);

/// @brief Define parameter for set model file <br>
/// It is a required parameter
DEFINE_string(m, "", model_message);

/// @brief Define parameter for set path to plugins <br>
DEFINE_string(pp, "", plugin_path_message);

/// @brief device the target device to infer on <br>
DEFINE_string(d, "CPU", target_device_message);

/// \brief Enable per-layer performance report
DEFINE_bool(pc, false, performance_counter_message);

/// @brief Define parameter for clDNN custom kernels path <br>
/// Default is ./lib
DEFINE_string(c, "", custom_cldnn_message);

/// @brief Absolute path to CPU library with user layers <br>
/// It is a optional parameter
DEFINE_string(l, "", custom_cpu_library_message);

/// @brief Iterations count (default 1)
DEFINE_int32(ni, 1, iterations_count_message);

/// @brief Custom bbox layer name
DEFINE_string(bbox_name, "bbox_pred", bbox_layer_name_message);
/// @brief Custom proposal layer name
DEFINE_string(proposal_name, "proposal", proposal_layer_name_message);
/// @brief Custom prob layer name
DEFINE_string(prob_name, "cls_prob", prob_layer_name_message);

/// @brief Enable plugin messages
DEFINE_bool(p_msg, false, plugin_message);

/**
* @brief This function show a help message
*/
static void showUsage() {
    std::cout << std::endl;
    std::cout << "object_detection_demo [OPTION]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << std::endl;
    std::cout << "    -h                        " << help_message << std::endl;
    std::cout << "    -i \"<path>\"               " << image_message << std::endl;
    std::cout << "    -m \"<path>\"               " << model_message << std::endl;
    std::cout << "      -l \"<absolute_path>\"    " << custom_cpu_library_message << std::endl;
    std::cout << "      -c \"<absolute_path>\"    " << custom_cldnn_message << std::endl;
    std::cout << "    -pp \"<path>\"              " << plugin_path_message << std::endl;
    std::cout << "    -d \"<device>\"             " << target_device_message << std::endl;
    std::cout << "    -pc                       " << performance_counter_message << std::endl;
    std::cout << "    -ni \"<integer>\"           " << iterations_count_message << std::endl;
    std::cout << "    -bbox_name \"<string>\"     " << bbox_layer_name_message << std::endl;
    std::cout << "    -proposal_name \"<string>\" " << proposal_layer_name_message << std::endl;
    std::cout << "    -prob_name \"<string>\"     " << prob_layer_name_message << std::endl;
    std::cout << "    -p_msg                    " << plugin_message << std::endl;
}
