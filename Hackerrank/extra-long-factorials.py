#!/bin/python

import sys
def factorial(n):
    if n==1:
        return n
    return n*factorial(n-1)

n = int(raw_input().strip())
print(factorial(n))