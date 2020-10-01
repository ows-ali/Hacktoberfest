#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the saveThePrisoner function below.
# n = number of prisoners
# m = number of sweets
# s = starting position
def saveThePrisoner(n, m, s):
    s2 = s - 1 # zero indexing makes more sense for modular arithmetic
    w = (s2 + (m - 1)) % n # first sweet at position s2, loops around at n
    return w + 1 # adjust to get rid of zero indexing

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        nms = input().split()

        n = int(nms[0])

        m = int(nms[1])

        s = int(nms[2])

        result = saveThePrisoner(n, m, s)

        fptr.write(str(result) + '\n')

    fptr.close()
