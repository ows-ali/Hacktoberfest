#!/bin/python3

"""
    Author: Rishabh Kaushik
    e-mail: rishabhrkaushik@gmail.com
    website: https://rishabhrkaushik.github.io

    Purpose: This is part of the series to the solution to Project Euler.
    Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler005
"""

import sys

primes = [1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]

def calculateFactor(factors):
    # return if current maximum factor is prime
    if(max(factors) in primes):
        return factors
    else:
        # calculate prime factors of largest number
        m = max(factors)
        factors.remove(m)
        if(m % 2 == 0):
            factors.append(2)
            factors.append(m//2)
        else:
            for i in range(3, (m//3) + 1, 2):
                if(m % i == 0):
                    factors.append(i)
                    factors.append(m//i)
                    break
    return calculateFactor(factors)

def findLCM(n):
    list_of_factors = []
    # calculate factors of all numbers less than equal to n
    for i in range(1, n+1):
        list_of_factors.append(calculateFactor([i]))
    lcm = 1
    # lcm = lcm * primes ^ (max times it occur in factors of any number)
    for i in range(12):
        lcm = lcm * primes[i] ** max(factors.count(primes[i]) for factors in list_of_factors)
    return lcm

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(findLCM(n))
