#ifndef CARTESIAN_MESH_2D_H
#define CARTESIAN_MESH_2D_H

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
/// \brief Header containing the class for a 2D Cartesian Mesh.
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// local
////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdexcept>

namespace menumgee {
////////////////////////////////////////////////////////////////////////////
/// \defgroup Grids Grids
/// \brief    A collection of grids.
/// @{
////////////////////////////////////////////////////////////////////////////
/// \brief A structured cartesian mesh in 2D.
/// \tparam Scalar_T The scalar type.
template<typename Scalar_type>
class Cartesian_Mesh_2D {
public:
  //////////////////////////////////////////////////////////////////////////
  /// \brief The scalar type used in the mesh.
  using Scalar_T = Scalar_type;

  //////////////////////////////////////////////////////////////////////////
  /// \brief Default constructor.
  Cartesian_Mesh_2D() = default;

  //////////////////////////////////////////////////////////////////////////
  /// \brief Copy constructor.
  Cartesian_Mesh_2D(const Cartesian_Mesh_2D&) = default;

  //////////////////////////////////////////////////////////////////////////
  /// \brief Move constructor.
  Cartesian_Mesh_2D(Cartesian_Mesh_2D&&) = default;

  //////////////////////////////////////////////////////////////////////////
  /// \brief Copy assignment operator.
  Cartesian_Mesh_2D& operator=(const Cartesian_Mesh_2D&) = default;

  //////////////////////////////////////////////////////////////////////////
  /// \brief Move assignment operator.
  Cartesian_Mesh_2D& operator=(Cartesian_Mesh_2D&&) = default;

  Cartesian_Mesh_2D(const Scalar_type& x_min_in,
                    const Scalar_type& x_max_in,
                    const Scalar_type& num_cells_x_in,
                    const Scalar_type& y_min_in,
                    const Scalar_type& y_max_in,
                    const Scalar_type& num_cells_y_in) :
    x_min(x_min_in),
    x_max(x_max_in),
    num_cells_x(num_cells_x_in),
    y_min(y_min_in),
    y_max(y_max_in),
    num_cells_y(num_cells_y_in) {
      if(num_cells_x == 0 || num_cells_y == 0) {
        throw std::runtime_error("The number of cells in each direction must be greater than 0!");
      }

      dx = (x_max - x_min)/num_cells_x;
      dy = (y_max - y_min)/num_cells_y;
    }

protected:
  //////////////////////////////////////////////////////////////////////////
  /// \brief The value of the minimum x node.
  Scalar_T x_min;

  //////////////////////////////////////////////////////////////////////////
  /// \brief The value of the maximum x node.
  Scalar_T x_max;

  //////////////////////////////////////////////////////////////////////////
  /// \brief The number of cells in the x-direction.
  Scalar_T num_cells_x;

  //////////////////////////////////////////////////////////////////////////
  /// \brief The length of a cell face in the x-direction.
  Scalar_T dx;

  //////////////////////////////////////////////////////////////////////////
  /// \brief The value of the minimum y node.
  Scalar_T y_min;

  //////////////////////////////////////////////////////////////////////////
  /// \brief The value of the maximum y node.
  Scalar_T y_max;

  //////////////////////////////////////////////////////////////////////////
  /// \brief The number of cells in the y-direction.
  Scalar_T num_cells_y;

  //////////////////////////////////////////////////////////////////////////
  /// \brief The length of a cell face in the y-direction.
  Scalar_T dy;
}; // class Cartesian_Mesh_2D

// @}

} // namespace menumgee

#endif // #ifndef CARTESIAN_MESH_2D_H