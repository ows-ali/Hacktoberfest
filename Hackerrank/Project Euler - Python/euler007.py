#!/bin/python3

"""
    Author: Rishabh Kaushik
    e-mail: rishabhrkaushik@gmail.com
    website: https://rishabhrkaushik.github.io

    Purpose: This is part of the series to the solution to Project Euler.
    Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler007/problem
"""

import sys


t = int(input().strip())

allN = []
for a0 in range(t):
    n = int(input().strip())
    # add all n to a list to find m prime numbers where m is largest n required
    allN.append(n)

allPrimes = [2]
currentNumber = 3

# check if num is divisible with any prime number before it
def isPrime(num, allPrimes):
    #print(num, allPrimes)
    for prime in allPrimes:
        #print(prime)
        if (num % prime == 0):
            #print(False)
            return False
    return True

# add first m prime number to a list
while(len(allPrimes) < max(allN)):
    # append to list if the number is prime
    if(isPrime(currentNumber, allPrimes)):
        allPrimes.append(currentNumber)
    currentNumber += 2

#print(allPrimes)
for num in allN:
    print(allPrimes[num - 1])
