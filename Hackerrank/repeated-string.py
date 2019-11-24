#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s, n):
    strLen = len(s)

    aInS = s.count('a')
    aInSubS = s[:n%strLen].count('a')

    numA = int(n/strLen)*aInS + aInSubS
    return(numA)


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()
