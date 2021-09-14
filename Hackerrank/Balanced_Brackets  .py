#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the isBalanced function below.
def isBalanced(s):
    found = []
    d = {'(':')', '{':'}', '[':']'}
    k, v = d.keys(), d.values()
    no = 'NO'

    for symbol in s:
        if symbol in k:
            found.append(symbol)
        elif symbol in v:
            if not found:
                return no
            elif d[found[-1]] == symbol:
                found.pop(-1)
            else:
                return no
    if found:
        return no
    return 'YES'


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        s = input()

        result = isBalanced(s)

        fptr.write(result + '\n')

    fptr.close()
