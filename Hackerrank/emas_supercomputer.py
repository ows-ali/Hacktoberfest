y, x = [int(i) for i in str(input()).split(" ")]

a = [list(input()) for i in range(0, y)]

possible_centers = []

min_side = min([x, y])

for i in range(min_side // 2, min_side):
    if a[i][i] == 'G' and i == min_side // 2:
        possible_centers.append([i, i])
    else:
        if a[i][i] == 'G':
            possible_centers.append([i, i])

        if a[min_side - i][min_side - i] == 'G':
            possible_centers.append([min_side - i, min_side - i])

        if a[min_side - i][i] == 'G':
            possible_centers.append([min_side - i, i])

        if a[min_side - i][i] == 'G':
            possible_centers.append([i, min_side - i])

for c in possible_centers:
    hor_min = min([c[0] - 1, min_side - 1 - c[0]])
    ver_mn = min([c[1] - 1, min_side - 1 - c[1]])
    print("horizontal: ", 'G' * (hor_min * 2 + 1), "vertical: ",
          'G' * (ver_mn * 2 + 1))
    hor_cells = a[c[0]]
    ver_cell = a[c[1]]

    print(
        ''.join(hor_cells[abs(c[1] - hor_min):c[1]]) + hor_cells[c[1]] +
        ''.join(hor_cells[c[1]:c[1] + hor_min]),
        ''.join(ver_cell[abs(c[0] - ver_min):c[0]]) + ver_cell[c[0]] +
        ''.join(ver_cell[c[0]:c[0] + ver_min]))

print(possible_centers)