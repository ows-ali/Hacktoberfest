import math
test = int(input())
while test:
    d = int(input())
    s = input()
    current = s.count('P')
    proxy = 0
    for x in range(2, d - 2):
        if (current + proxy) >= math.ceil(0.75*d):
            break
        elif s[x] == 'A'and ((s[x-1] == 'P' or s[x-2] == 'P') and (s[x+1] == 'P' or s[x+2] == 'P')):
            proxy += 1
    if (current + proxy) < math.ceil(0.75*d):
        print(-1)
    else:
        print(proxy)
    test -= 1# cook your dish here
