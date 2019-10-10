#!/bin/python3

import sys


t = int(input().strip())
for a0 in range(t):
    c=0
    n,k = input().strip().split(' ')
    n,k = [int(n),int(k)]
    a = [int(a_temp) for a_temp in input().strip().split(' ')]
    for i in a :
        if i<=0:
            c=c+1
    if(c>=k):
        print("NO")
    else:
        print("YES")
