# ######################################################################
# ######################################################################
# # CMakeLists.txt for MeNumGee
# # subdirectory: Grids
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
# # Tests
# ######################################################################

# ######################################################################
# # Setting the name of the PyBind module
# ######################################################################
option(MENUMGEE_Grids "Compile the MeNumGee utilities module" ON)

# ######################################################################
# # Python Module
# ######################################################################
if (MENUMGEE_Grids)
  MeNumGee_add_pybind11_module(grids Grids_Python_Module.cpp)
endif()