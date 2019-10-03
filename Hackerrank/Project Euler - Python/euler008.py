#!/bin/python3

"""
    Author: Rishabh Kaushik
    e-mail: rishabhrkaushik@gmail.com
    website: https://rishabhrkaushik.github.io

    Purpose: This is part of the series to the solution to Project Euler.
    Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler008/problem
"""

import sys


t = int(input().strip())
for a0 in range(t):
    n,k = input().strip().split(' ')
    n,k = [int(n),int(k)]
    num = input().strip()
    products = []
    digits = []
    # seperate out the digits
    for i in range(n):
        digits.append(int(str(num)[i]))
    # loop to calculate all the posible products
    for i in range(n - k + 1):
        product = 1
        # calculate product of digits of individual numbers
        for j in range(k):
            product = product * digits[i + j]
        products.append(product)
    # find max of all products 
    print(max(products))
