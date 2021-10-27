q = int(input())

for i in range(0, q):
    n = int(input())
    cont_type = []
    ball_type = []
    matrix = []
    for j in range(0, n):
        matrix.append(list( [ int(k) for k in str(input()).split(" ")]))
    #print(matrix)

    for col_index in range(0,n):
        col_sum = 0
        row_sum = 0
        for row_index in range(0, n):
            col_sum+= matrix[col_index][row_index]
            row_sum+= matrix[row_index][col_index]
        cont_type.append(row_sum)
        ball_type.append(col_sum)
    if sorted(cont_type) == sorted(ball_type):
        print("Possible")
    else:
        print("Impossible")

  
    



