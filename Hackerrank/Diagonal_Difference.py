#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def diagonalDifference(arr):
    """Computes the Diagnol Difference of a square matrix"""

    # calculates right to left diagonal sum
    def right_to_left(arr): 

        right_to_left_sum = []

        # iterating through matrix
        for i in range(len(arr)):
            right_to_left_sum.append(arr[i][-i-1])

        return sum(right_to_left_sum)

    # calculates left to right diagonal sum
    def left_to_right(arr):

        left_to_right_sum = []

        # iterating through matrix
        for i in range(len(arr)):
            left_to_right_sum.append(arr[i][i])

        return sum(left_to_right_sum)

    return abs(right_to_left(arr) - left_to_right(arr))


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
