#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the cutTheSticks function below.
def cutTheSticks(arr):
    out = []
    while len(arr) > 0:
        print(arr)
        out.append(len(arr))
        a = min(arr)
        for i in range(len(arr)):
            arr[i] = arr[i]-a
        arr = list(filter(lambda a: a != 0, arr))
    return out


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = cutTheSticks(arr)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
