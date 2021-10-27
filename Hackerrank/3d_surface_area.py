h , w = [ int(p) for p in str(input()).split(" ")]

a = [ [ int(k) for k in str(input()).split(" ")] for i in range(0, h)]


def find_surface_area():
    surface_area = 0
    #exc = -1
    for row in range(0, h):
        for col in range(0, w):
            
            if row >= 0 and col > 0 and row < h-1 and col <= w-1:
                #exc = 0 
                surface_area += (6*a[row][col] - 2*(a[row][col] -1) - 2*(min([a[row][col-1], a[row][col]]) ) - 2*(min([a[row+1][col], a[row][col]])))
            elif col == 0 and row < h-1:
                #exc = 1
                surface_area += (6*a[row][col] - 2*(a[row][col] -1)  -2*(min([a[row+1][col], a[row][col]])))
            elif row == h-1 and col > 0:
                #exc = 2
                surface_area += (6*a[row][col] - 2*(a[row][col] -1)  - 2*(min([a[row][col-1], a[row][col]])))
            else:
                #exc = 3
                surface_area += (6*a[row][col] - 2*(a[row][col] -1))
            #print("row: ", row, " col: ",col, "a[i][j]: ", a[row][col], " surface_area: ", surface_area, "exec: ", exc)

    print(surface_area)


find_surface_area()