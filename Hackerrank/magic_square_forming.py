# Problem Link: https://www.hackerrank.com/challenges/magic-square-forming/problem

# Complete the formingMagicSquare function below.
def formingMagicSquare(s):

    sol = [[4,9,2],
            [3,5,7],
            [8,1,6]]

    # Functions to generate variations of sol, that are also magic squares.
    def transpose(mat):
        trans = [row[:] for row in mat]
        for row in range(len(mat)):
            for col in range(row+1,len(mat[0])):
                trans[row][col],trans[col][row] = trans[col][row],trans[row][col]

        return trans

    def reflect(mat):
        trans = [row[:] for row in mat]
        for row in range(len(mat)):
            trans[row] = trans[row][::-1]
        return trans

    # Utility function for debugging
    def printmat(mat):
        for row in mat:
            print(row)

    # Generating all the diffrent magic sqaures.
    reflect90 = reflect(transpose(sol))
    reflect180 = reflect(transpose(reflect90))
    reflect270 = reflect(transpose(reflect180))

    ref = reflect(sol)
    refref90 = reflect(reflect90)
    refref180 = reflect(reflect180)
    refref270 = reflect(reflect270)

    solutions = [sol,ref,reflect90,reflect180,reflect270,refref90,refref180,refref270]

    # Calculating difference between each solution in magic square and input matrix.
    min_diff = pow(2,31)
    for sol in solutions:
        diff = 0
        for i in range(len(sol)):
            for j in range(len(sol[0])):
                diff+=abs(sol[i][j]-s[i][j])
        if diff<min_diff:
            min_diff = diff

    return min_diff


if __name__ == '__main__':
    s = []

    # Sample input format:
    # 1 2 3
    # 4 5 6
    # 7 8 9

    # Sample output:
    # 24

    for _ in range(3):
        s.append(list(map(int, input().rstrip().split())))

    result = formingMagicSquare(s)

    print(result)
