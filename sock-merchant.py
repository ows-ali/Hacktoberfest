#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    x = {}
    p = 0
    for i in ar:
        c = 0
        for j in ar:
            if i == j:
                c += 1
        x[i] = c
    for i in x:
        p += x[i]//2
    return p
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
