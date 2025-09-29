# ######################################################################
# ######################################################################
# #                   src/CMake/BuildType.cmake
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

set(PYTHON_MODULE_NAME "menumgee")

# ######################################################################
# # Setup PyBind11
# ######################################################################
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)

target_link_libraries(NumsGoBrr PRIVATE Python3::Python)

# ######################################################################
# # Setting up the MeNumGee python module
# ######################################################################
set(MENUMGEE_MODULE_INIT_PY "${CMAKE_CURRENT_BINARY_DIR}/${PYTHON_MODULE_NAME}/__init__.py")

set(MENUMGEE_MODULE_INIT_PY_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
  GROUP_EXECUTE GROUP_READ
  WORLD_EXECUTE WORLD_READ)

file(WRITE  ${MENUMGEE_MODULE_INIT_PY} "################################################\n")
file(APPEND ${MENUMGEE_MODULE_INIT_PY} "# MENUMGEE Python Module\n")
file(APPEND ${MENUMGEE_MODULE_INIT_PY} "################################################\n")

# ######################################################################
# # Module registration
# ######################################################################
function(MENUMGEE_add_pybind11_module name file)
  pybind11_add_module(${name} ${file})

  set_property(TARGET ${name}
    PROPERTY LIBRARY_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/${PYTHON_MODULE_NAME})

  target_link_libraries(${name} PRIVATE menumgee_project_dependencies)

  target_compile_definitions(${name} PRIVATE MENUMGEE_PYTHON_MODULE)

  file(APPEND ${MENUMGEE_MODULE_INIT_PY} "\n")
  file(APPEND ${MENUMGEE_MODULE_INIT_PY} "################################################\n")
  file(APPEND ${MENUMGEE_MODULE_INIT_PY} "## Import Module: ${name}\n")
  file(APPEND ${MENUMGEE_MODULE_INIT_PY} "################################################\n")
  file(APPEND ${MENUMGEE_MODULE_INIT_PY} "from .${name} import *\n")
endfunction()