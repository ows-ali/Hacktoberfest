#!/bin/python3

"""
    Author: Rishabh Kaushik
    e-mail: rishabhrkaushik@gmail.com
    website: https://rishabhrkaushik.github.io

    Purpose: This is part of the series to the solution to Project Euler.
    Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem
"""

import sys


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    # used sum of AP to make the problem O(1)
    # sum of AP = n/2 * [2*a+(n−1) * d]  where n is number of terms, a is first term, d is difference between 2 terms
    # n3 = number of terms in AP with d = 3
    # sum3 = sum of AP
    n3 = (n-1)//3
    sum3 = n3 * (6 + ((n3-1) * 3))
    n5 = (n-1)//5
    sum5 = n5 * (10 + ((n5-1) * 5))
    n15 = (n-1)//15
    sum15 = n15 * (30 + ((n15-1) * 15))
    sum = sum3 + sum5 - sum15
    print(sum//2)
