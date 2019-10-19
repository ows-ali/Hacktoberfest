#!/bin/python3
# https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem
import sys


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    n -= 1
    n_3 = n//3
    n_5 = n//5
    n_15 = n//15
    s_3 = (3*n_3*(n_3 + 1))//2
    s_5 = (5*n_5*(n_5 + 1))//2
    s_15 = (15*n_15*(n_15 + 1))//2
    print(s_3+s_5-s_15)


