#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumAbsoluteDifference function below.
def minimumAbsoluteDifference(a):
    if len(a) != len(set(a)):
        return 0
    return min(abs(x-y) for x,y in zip(a,a[1:]))
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    a =sorted(map(int, input().split()))
    

    fptr.write(str(minimumAbsoluteDifference(a)) + '\n')

    fptr.close()
