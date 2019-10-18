#!/bin/python3
#ANUNEET ANAND
import math
import os
import random
import re
import sys

# Complete the plusMinus function below.
def plusMinus(arr):
    x=y=z=0
    for i in arr:
        if i>0:
            x=x+1
        elif i<0:
            y=y+1
        else:
            z=z+1
    print(x/len(arr))
    print(y/len(arr))
    print(z/len(arr))
if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)

