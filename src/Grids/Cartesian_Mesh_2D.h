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
#include <utility>
#include <vector>

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
                    const Scalar_type& num_cells_y_in,
                    const Scalar_type& num_quadrature_points_per_face_in,
                    const Scalar_type& num_quadrature_points_per_volume_in) :
    x_min(x_min_in),
    x_max(x_max_in),
    num_cells_x(num_cells_x_in),
    y_min(y_min_in),
    y_max(y_max_in),
    num_cells_y(num_cells_y_in),
    num_quadrature_points_per_face(num_quadrature_points_per_face_in),
    num_quadrature_points_per_volume(num_quadrature_points_per_volume_in) {
      if(num_cells_x == 0 || num_cells_y == 0) {
        throw std::runtime_error("The number of cells in each direction must be greater than 0!");
      }

      if(num_quadrature_points_per_face < 0 || num_quadrature_points_per_face > 3) {
        throw std::runtime_error("Unsupported number of face quadrature points!");
      }

      if(num_quadrature_points_per_volume < 0 || num_quadrature_points_per_volume > 3) {
        throw std::runtime_error("Unsupported number of volume quadrature points!");
      }

      dx = (x_max - x_min)/num_cells_x;
      dy = (y_max - y_min)/num_cells_y;
    }

  /////////////////////////////////////////////////////////////////////////
  /// \brief Returns the number of cells in the grid
  size_t num_cells() {
    return num_cells_x*num_cells_y;
  }

  //////////////////////////////////////////////////////////////////////////
  /// \brief Returns the 1D flattened index from the 2D index (i, j).
  size_t get_idx(const size_t i, const size_t j) {
    if(i < 0 || i >= num_cells_x || j < 0 || j >= num_cells_y) {
      throw std::runtime_error("The cell index is out of range!");
    }
    return j * num_cells_x + i;
  }

  //////////////////////////////////////////////////////////////////////////
  /// \brief Returns the 2D index (i, j) from a 1D flattened index.
  std::pair<size_t, size_t> get_i_and_j(const size_t idx) {
    if(idx >= num_cells_x * num_cells_y) {
      throw std::runtime_error("The cell index is out of range!");
    }
    size_t j = idx / num_cells_x;
    size_t i = idx % num_cells_x;
    return {i, j};
  }

  /////////////////////////////////////////////////////////////////////////
  /// \brief Returns the cell centroid in the grid based on the input
  ///        of a two dimensional index.
  std::pair<Scalar_T, Scalar_T> cell_centroid(const size_t i, const size_t j) {
    if(i < 0 || i >= num_cells_x || j < 0 || j >= num_cells_y) {
      throw std::runtime_error("The cell index is out of range");
    }

    const Scalar_T x_centroid = x_min + (static_cast<Scalar_T>(i) + 0.5)*dx;
    const Scalar_T y_centroid = y_min + (static_cast<Scalar_T>(j) + 0.5)*dy;

    return {x_centroid, y_centroid};
  }

  /////////////////////////////////////////////////////////////////////////
  /// \brief Returns a vector of cell quadrature points along each face
  std::vector<std::pair<Scalar_T, Scalar_T>> face_quadrature_points(const size_t i, const size_t j) {
    if(num_quadrature_points_per_face == 0) {
      return {};
    }
  }

  /////////////////////////////////////////////////////////////////////////
  /// \brief Returns a vector of quadrature points in each cell volume
  std::vector<std::pair<Scalar_T, Scalar_T>> volume_quadrature_points(const size_t i, const size_t j) {
    if(num_quadrature_points_per_volume == 0) {
      return {};
    }
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
  size_t num_cells_x;

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
  size_t num_cells_y;

  //////////////////////////////////////////////////////////////////////////
  /// \brief The length of a cell face in the y-direction.
  Scalar_T dy;

  //////////////////////////////////////////////////////////////////////////
  /// \brief The number of quadrature points on a cell face.
  size_t num_quadrature_points_per_face;

  //////////////////////////////////////////////////////////////////////////
  /// \brief The number of quadrature points in a cell volume.
  size_t num_quadrature_points_per_volume;
}; // class Cartesian_Mesh_2D

// @}

} // namespace menumgee

#endif // #ifndef CARTESIAN_MESH_2D_H