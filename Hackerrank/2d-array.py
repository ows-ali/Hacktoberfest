import math
import os
import random
import re
import sys

def hourglassSum(array):
    max_sum = -63;
    for row in range(0, len(array)-2):
        for column in range(0, len(array)-2):
            top = array[row][column] + array[row][column+1] + array[row][column+2] 
            middle = array[row+1][column+1]
            bottom = array[row+2][column] + array[row+2][column+1] + array[row+2][column+2] 
            result = top + middle + bottom
            if result > max_sum:
                max_sum = result
    return max_sum

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    array = []

    for _ in range(6):
        array.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(array)

    fptr.write(str(result) + '\n')

    fptr.close()
