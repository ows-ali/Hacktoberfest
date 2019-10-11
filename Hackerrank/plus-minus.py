#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the plusMinus function below.
def plusMinus(arr):
    n = len(arr)

    print(sum(map(lambda x: 1 if x > 0 else 0, arr)) / n)
    print(sum(map(lambda x: 1 if x < 0 else 0, arr)) / n)
    print(sum(map(lambda x: 1 if x == 0 else 0, arr)) / n)

if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)

