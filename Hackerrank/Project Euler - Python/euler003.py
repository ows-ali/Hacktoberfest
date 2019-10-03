#!/bin/python3

"""
    Author: Rishabh Kaushik
    e-mail: rishabhrkaushik@gmail.com
    website: https://rishabhrkaushik.github.io

    Purpose: This is part of the series to the solution to Project Euler.
    Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler003/problem
"""

import sys

# used from https://stackoverflow.com/questions/15285534/isprime-function-for-python-language
# return is a number is prime
def isPrime(n):
	if n == 2 or n == 3: return True
	if n < 2 or n%2 == 0: return False
	if n < 9: return True
	if n%3 == 0: return False
	r = int(n**0.5)
	f = 5
	while f <= r:
		if n%f == 0: return False
		if n%(f+2) == 0: return False
		f +=6
	return True

def calculateFactor(factors):
	# return if current maximum factor is prime
    if(isPrime(max(factors))):
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

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    factors = []
    factors.append(n)
    print(max(calculateFactor(factors)))
