# ######################################################################
# ######################################################################
# #                  src/CMake/GTest.cmake
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

#######################################################################
## Find package for Google unit tests
#######################################################################
find_package(GTest CONFIG REQUIRED)

#######################################################################
## Test suite application
#######################################################################
add_executable(NumsGoBrr test_suite.cpp)
target_link_libraries(NumsGoBrr PRIVATE GTest::gtest)
target_link_libraries(NumsGoBrr PRIVATE menumgee_project_dependencies)

function(MeNumGee_add_to_tests file)
  target_sources(NumsGoBrr PRIVATE ${file})
endfunction()