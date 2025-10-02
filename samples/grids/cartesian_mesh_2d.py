##############################################################################################
# Importing libraries
##############################################################################################
# import system paths
import sys
sys.path.insert(1, '../../build/')

import menumgee as mng

def output(phrase, value):
  print(phrase)
  print('-------------------------------')
  print(value)
  print('')

x_min       = -0.5
x_max       = 0.5
num_cells_x = 100
y_min       = -0.5
y_max       = 0.5
num_cells_y = 100

grid = mng.grids.cartesian_mesh_2d(x_min, x_max, num_cells_x, y_min, y_max, num_cells_y, 0, 0)

output('Number of Cells', grid.num_cells())
output('Cell Centroid for index i = 5 and j = 50', grid.cell_centroid(5, 50))