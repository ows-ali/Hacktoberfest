# Minimum Swaps 2: https://www.hackerrank.com/challenges/minimum-swaps-2/problem

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumSwaps function below.

def swap(a, b):
    tmp = a
    a = b
    b = tmp

def minimumSwaps(arr):
    largest = len(arr)
    swaps = 0
    i = 0
    while i < largest:
        if arr[i] == i + 1:
            i += 1
            continue
        loc = arr[i] - 1
        arr[i], arr[loc] = arr[loc], arr[i]
        swaps += 1
    return swaps

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = minimumSwaps(arr)

    fptr.write(str(res) + '\n')

    fptr.close()
