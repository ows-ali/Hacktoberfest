def diagonalDifference(arr):
    primary_diagonal = 0
    secondary_diagonal = 0
    n = len(arr)
    
    for i in range(n):
        primary_diagonal += arr[i][i]
        secondary_diagonal += arr[i][n - i - 1]
    
    return abs(primary_diagonal - secondary_diagonal)

# Input handling
n = int(input())
arr = []

for _ in range(n):
    arr.append(list(map(int, input().split())))

# Function call and output
print(diagonalDifference(arr))
