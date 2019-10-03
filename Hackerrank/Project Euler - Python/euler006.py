#!/bin/python3

"""
    Author: Rishabh Kaushik
    e-mail: rishabhrkaushik@gmail.com
    website: https://rishabhrkaushik.github.io

    Purpose: This is part of the series to the solution to Project Euler.
    Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler006/problem
"""

import sys


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    # sum of first n natural number squared - sum of square of first n natural number
    diff = (n*(n+1)/2)**2 - ((n**3)/3 + (n**2)/2 + (n/6))
    print(int(diff))
