
import math
import os
import random
import re
import sys

# Complete the plusMinus function below.
def plusMinus(arr):
    s= len(arr)
    a=0
    b=0
    c=0
    for i in arr:
        if i > 0:
            a+=1
        elif i< 0:
            b+=1
        else:
            c+=1
    print(a/float(s))
    print(b/float(s))
    print(c/float(s))

if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)