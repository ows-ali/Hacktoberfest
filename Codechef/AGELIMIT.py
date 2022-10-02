#Read the number of test cases.
T = int(input())
for tc in range(T):
    # Read integers X, Y and A.
    (x, y, a) = map(int, input().split(' '))
    if(a<x):
        print('NO')
    elif(a>=y):
        print('NO')
    else:
        print('YES')