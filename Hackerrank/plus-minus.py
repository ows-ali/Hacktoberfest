# https://www.hackerrank.com/challenges/plus-minus/problem

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the plusMinus function below.
def plusMinus(arr):
    length = len(arr)
    zero_count = 0
    positive_count = 0
    negative_count = 0
    
    for i in arr:
        if i == 0:
            zero_count+= 1
        elif i > 0:
            positive_count += 1
        else:
            negative_count += 1
    
    positive_frac = round(positive_count, 6) / length
    negative_frac = round(negative_count, 6) / length
    zero_frac = round(zero_count, 6) / length

    print(positive_frac)
    print(negative_frac)
    print(zero_frac)

if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)