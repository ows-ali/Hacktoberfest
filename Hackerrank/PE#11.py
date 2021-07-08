grid = []
mp=0
for grid_i in range(20):
   grid_t = [int(grid_temp) for grid_temp in input().strip().split(' ')]
   grid.append(grid_t)
for row in range(20):
  for column in range(17):
    pv=max(grid[row][column]*grid[row][column+1]*grid[row][column+2]*grid[row][column+3],grid[column][row]*grid[column+1][row]*grid[column+2][row]*grid[column+3][row])
    if row<17:
      pd=max(grid[row][column]*grid[row+1][column+1]*grid[row+2][column+2]*grid[row+3][column+3],grid[row][column+3]*grid[row+1][column+2]*grid[row+2][column+1]*grid[row+3][column])
    mp=max(mp,pv,pd)
print(mp)
