#ifndef CARTESIAN_MESH_2D_PYTHON_MODULE_H
#define CARTESIAN_MESH_2D_PYTHON_MODULE_H

////////////////////////////////////////////////////////////////////////////
// This file is part of the MeNumGee software for numerical development
// in Python. It is licensed under the MIT License. A copy of this
// license, in a file named LICENSE.md, should have been distributed
// with this file. A copy of this license is also currently available
// at "https://opensource.org/licenses/MIT".

// Unless explicitly stated, all contributions intentionally submitted
// to this project shall also be under the terms and conditions of this
// license, without any additional terms or conditions.
////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief Python module for a 2D Cartesian Mesh in Grids.
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// local
////////////////////////////////////////////////////////////////////////////
#include "Cartesian_Mesh_2D.h"

////////////////////////////////////////////////////////////////////////////
// pybind
////////////////////////////////////////////////////////////////////////////
#include <pybind11/chrono.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

namespace py = pybind11;

///////////////////////////////////////////////////////////////////////
// Defining types
//////////////////////////////////////////////////////////////////////
using Scalar_T = double;
using Cartesian_Mesh_2D_T = menumgee::Cartesian_Mesh_2D<Scalar_T>;

void cartesian_mesh_2d_module(py::module& m) {
  py::class_<Cartesian_Mesh_2D_T> grid(m, "cartesian_mesh_2d", R"delim(
    )delim");

  grid.def(py::init<const Scalar_T&,
                    const Scalar_T&,
                    const size_t&,
                    const Scalar_T&,
                    const Scalar_T&,
                    const size_t&,
                    const size_t&,
                    const size_t&>(), R"delim(
    )delim",
    py::arg("x_min"),
    py::arg("x_max"),
    py::arg("num_cells_x"),
    py::arg("y_min"),
    py::arg("y_max"),
    py::arg("num_cells_y"),
    py::arg("num_quadrature_points_per_face"),
    py::arg("num_quadrature_points_per_volume"));

  grid.def("num_cells", &Cartesian_Mesh_2D_T::num_cells, R"delim(
  )delim");

  grid.def("cell_centroid", &Cartesian_Mesh_2D_T::cell_centroid, R"delim(
  )delim",
  py::arg("i"),
  py::arg("j"));
}

#endif // #ifndef CARTESIAN_MESH_2D_PYTHON_MODULE_H