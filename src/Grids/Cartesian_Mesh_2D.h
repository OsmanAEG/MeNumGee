#ifndef CARTESIAN_MESH_2D_H
#define CARTESIAN_MESH_2D_H

///////////////////////////////////////////////////////////////////////////
// This file is part of the MeNumGee software for numerical development
// in Python. It is licensed under the MIT License. A copy of this
// license, in a file named LICENSE.md, should have been distributed
// with this file. A copy of this license is also currently available
// at "https://opensource.org/licenses/MIT".

// Unless explicitly stated, all contributions intentionally submitted
// to this project shall also be under the terms and conditions of this
// license, without any additional terms or conditions.
///////////////////////////////////////////////////////////////////////
/// \file
/// \brief Header containing the class for a 2D Cartesian Mesh.
///////////////////////////////////////////////////////////////////////////

namespace menumgee {
///////////////////////////////////////////////////////////////////////////
/// \defgroup Grids Grids
/// \brief    A collection of grids.
/// @{
///////////////////////////////////////////////////////////////////////////
/// \brief A structured cartesian mesh in 2D.
/// \tparam Scalar_T The scalar type.
template<typename Scalar_type>
class Cartesian_Mesh_2D {
public:
  /////////////////////////////////////////////////////////////////////////
  /// \brief The scalar type used in the mesh.
  using Scalar_T = Scalar_type;

  /////////////////////////////////////////////////////////////////////////
  /// \brief Default constructor.
  Cartesian_Mesh_2D() = default;

  /////////////////////////////////////////////////////////////////////////
  /// \brief Copy constructor.
  Cartesian_Mesh_2D(const Cartesian_Mesh_2D&) = default;

  /////////////////////////////////////////////////////////////////////////
  /// \brief Move constructor.
  Cartesian_Mesh_2D(Cartesian_Mesh_2D&&) = default;

  /////////////////////////////////////////////////////////////////////////
  /// \brief Copy assignment operator.
  Cartesian_Mesh_2D& operator=(const Cartesian_Mesh_2D&) = default;

  /////////////////////////////////////////////////////////////////////////
  /// \brief Move assignment operator.
  Cartesian_Mesh_2D& operator=(Cartesian_Mesh_2D&&) = default;

  Cartesian_Mesh_2D(const Scalar_type& num_cells_x_in,
                    const Scalar_type& dx_in,
                    const Scalar_type& num_cells_y_in,
                    const Scalar_type& dy_in) :
    num_cells_x(num_cells_x_in),
    dx(dx_in),
    num_cells_y(num_cells_y_in),
    dy(dy_in) {}

protected:
  /////////////////////////////////////////////////////////////////////////
  /// \brief The number of cells in the x-direction.
  Scalar_T num_cells_x;

  /////////////////////////////////////////////////////////////////////////
  /// \brief The x-direction size of each cell.
  Scalar_T dx;

  /////////////////////////////////////////////////////////////////////////
  /// \brief The number of cells in the y-direction.
  Scalar_T num_cells_y;

  /////////////////////////////////////////////////////////////////////////
  /// \brief The y-direction size of each cell.
  Scalar_T dy;
}; // class Cartesian_Mesh_2D

} // namespace menumgee

#endif // #ifndef CARTESIAN_MESH_2D_H