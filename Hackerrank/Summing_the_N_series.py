#!/bin/python3

import os
import sys

#
# Complete the summingSeries function below.
#
def summingSeries(n):
    return (n**2 % int(1e9 + 7))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        result = summingSeries(n)

        fptr.write(str(result) + '\n')

    fptr.close()

