#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the cost function below.
def cost(b):
    n=len(b)
    l, h = 0, 0
    for i in range(1, n):
        l, h = (max(l, h + b[i - 1] - 1),
                max(l + b[i] - 1, h + abs(b[i] - b[i - 1])))
    return max(l, h)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        B = list(map(int, input().rstrip().split()))

        result = cost(B)

        fptr.write(str(result) + '\n')

    fptr.close()

