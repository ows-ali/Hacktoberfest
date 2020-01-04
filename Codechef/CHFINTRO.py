//https://www.codechef.com/DEC18B/problems/CHFINTRO

import math
n, k=map(int,input().split())
for t in range(n):
    t=int(input())
    while t>=k:
        print("Good boi")
        break
    while t<k:
        print("Bad boi")
        break