# cook your dish here
for i in range(int(input())):
    n = int(input())
    s= [int(x) for x in input().split()]
    s = sorted(s)
    x = 1000000000
    for j in range(n-1):
        diff = abs(s[j] - s[j+1])
        if diff < x:
            x = diff
    print(x)