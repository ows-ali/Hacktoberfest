#!/bin/python3

"""
    Author: Rishabh Kaushik
    e-mail: rishabhrkaushik@gmail.com
    website: https://rishabhrkaushik.github.io

    Purpose: This is part of the series to the solution to Project Euler.
    Problem Statement: https://www.hackerrank.com/contests/projecteuler/challenges/euler004/problem
"""

import sys

def largestPalindrome(n):
    start_point = n//1000
    # find palindrome less than n one by one by reciprocating string of first 3 digits
    for i in range(start_point, 100, -1):
        current_palindrome = int(str(i) + str(i)[::-1])
				# check if current palindrome can be written as multiplication of 2 three digit number
        for i in range(999, 100, -1):
        # check if current palindrome is less than n
            if(current_palindrome >= n):
                break
            if(current_palindrome%i == 0):
                if(current_palindrome//(1000 * i) == 0):
                    return current_palindrome

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(largestPalindrome(n))
