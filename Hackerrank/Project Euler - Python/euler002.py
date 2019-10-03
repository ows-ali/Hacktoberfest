#!/bin/python3

"""
    Author: Rishabh Kaushik
    e-mail: rishabhrkaushik@gmail.com
    website: https://rishabhrkaushik.github.io

    Purpose: This is part of the series to the solution to Project Euler.
    Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem
"""

import sys


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    i = 1
    j = 1
    k = 0
    sum = 0
    while(k < n):
        k = i + j
        i = j
        j = k
        if(k < n and k%2 == 0):
            sum = sum + k
    print(sum)
