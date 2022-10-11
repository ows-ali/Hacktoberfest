# cook your dish here
T = int(input())
for tc in range(T):
    (X, H) = map(int, input().split(' '))
    print('YES') if X>=H else print('NO')
