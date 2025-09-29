# ######################################################################
# ######################################################################
# #                  CMakeLists.txt for MeNumGee
# ######################################################################
# ######################################################################
# # This file is part of the MeNumGee software for numerical development
# # in Python. It is licensed under the MIT License. A copy of this
# # license, in a file named LICENSE.md, should have been distributed
# # with this file. A copy of this license is also currently available
# # at "https://opensource.org/licenses/MIT".
# #
# # Unless explicitly stated, all contributions intentionally submitted
# # to this project shall also be under the terms and conditions of this
# # license, without any additional terms or conditions.
# ######################################################################
# ######################################################################

cmake_minimum_required(VERSION 3.18)

project(MeNumGee LANGUAGES CXX CUDA)

# ######################################################################
# # Language standards
# ######################################################################
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CUDA_STANDARD 20)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

# ######################################################################
# # CUDA setup
# ######################################################################
set(CMAKE_CUDA_ARCHITECTURES 86)

find_package(CUDAToolkit REQUIRED)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# ######################################################################
# # Include dependencies for each module
# ######################################################################
add_library(menumgee_project_dependencies INTERFACE)

# ######################################################################
# # Build types
# ######################################################################
include(CMake/BuildType.cmake)

# ######################################################################
# # Google test
# ######################################################################
include(CMake/GTest.cmake)

# ######################################################################
# # PyBind
# ######################################################################
include(CMake/PyBind11.cmake)
