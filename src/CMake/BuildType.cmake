# ######################################################################
# ######################################################################
# #                  src/CMake/BuildType.cmake
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

# ######################################################################
# # Build types
# ######################################################################
set(DEFAULT_BUILD_TYPE "Release")

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}', as none was specified.")
  set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# ######################################################################
# # Build types for CPU
# ######################################################################
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "IntelLLVM")
  set(COMPILER_ARCH_FLAG "-xHost")
elseif(MSVC)
  set(COMPILER_ARCH_FLAG "")
else()
  set(COMPILER_ARCH_FLAG "-march=native")
endif()

# ######################################################################
# # C++ Flags
# ######################################################################
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG ${COMPILER_ARCH_FLAG}"    CACHE STRING "Release build flags (C++)." FORCE)
set(CMAKE_CXX_FLAGS_DEBUG   "-g"                                    CACHE STRING "Debug build flags (C++)."   FORCE)
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELEASE} -g"  CACHE STRING "RelWithDebInfo flags (C++)." FORCE)
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG ${COMPILER_ARCH_FLAG}" CACHE STRING "MinSizeRel flags (C++)."     FORCE)

# ######################################################################
# # CUDA Flags
# ######################################################################
set(_CUDA_COMMON "--expt-relaxed-constexpr --extended-lambda")

if (MSVC)
  set(_CUDA_HOST_WARN "/W3")
  set(CMAKE_CUDA_FLAGS_RELEASE "-O3 -DNDEBUG ${_CUDA_COMMON} -Xcompiler=${_CUDA_HOST_WARN}" CACHE STRING "Release build flags (CUDA)." FORCE)
  set(CMAKE_CUDA_FLAGS_DEBUG   "-G -g    ${_CUDA_COMMON} -Xcompiler=${_CUDA_HOST_WARN}"     CACHE STRING "Debug build flags (CUDA)."   FORCE)
else()
  set(_CUDA_HOST_WARN "-Wall,-Wextra")
  set(CMAKE_CUDA_FLAGS_RELEASE "-O3 -DNDEBUG ${_CUDA_COMMON} -Xcompiler=${_CUDA_HOST_WARN}" CACHE STRING "Release build flags (CUDA)." FORCE)
  set(CMAKE_CUDA_FLAGS_DEBUG   "-G -g    ${_CUDA_COMMON} -Xcompiler=${_CUDA_HOST_WARN}"     CACHE STRING "Debug build flags (CUDA)."   FORCE)
endif()

set(CMAKE_CUDA_FLAGS_RELWITHDEBINFO "${CMAKE_CUDA_FLAGS_RELEASE} -g" CACHE STRING "RelWithDebInfo flags (CUDA)." FORCE)
set(CMAKE_CUDA_FLAGS_MINSIZEREL     "-Os -DNDEBUG ${_CUDA_COMMON}"    CACHE STRING "MinSizeRel flags (CUDA)."     FORCE)