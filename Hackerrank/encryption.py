#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the encryption function below.
def encryption(s):

    spaceless = s.replace(" ", "")
    L = len(spaceless)
    root = math.sqrt(L)
    row_len = math.floor(root)
    col_len = math.ceil(root)

    if (row_len*col_len < L):
        row_len += 1

    grid = []
    word = []
    i = 0
    for letter in spaceless:
        word.append(letter)
        i += 1
        if (i == col_len):
            i = 0
            grid.append(word)
            word = []

    if word != []:
        grid.append(word)

    result = ""
    for col in range(col_len):
        for row in range(row_len):
            if col < len(grid[row]):
                result += grid[row][col]
        result += " "

    return result.strip()



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = encryption(s)

    fptr.write(result + '\n')

    fptr.close()
