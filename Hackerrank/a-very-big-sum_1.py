# https://www.hackerrank.com/challenges/a-very-big-sum/problem
# To test, delete the lines in the if block except for the commented lines.
# Next, uncomment the last three lines and run the program.

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the aVeryBigSum function below.
def aVeryBigSum(ar):
    valuesSum = 0
    for value in ar:
        valuesSum += value
    return valuesSum

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    ar_count = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = aVeryBigSum(ar)

    fptr.write(str(result) + '\n')

    fptr.close()

#    ar = [1000000001, 1000000002, 1000000003, 1000000004, 1000000005]
#    result = aVeryBigSum(ar)
#    print(result)
