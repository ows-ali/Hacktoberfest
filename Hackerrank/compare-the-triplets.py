#!/bin/python

import math
import os
import random
import re
import sys

# Complete the compareTriplets function below.
def compareTriplets(a, b):
    alice=0
    bob=0
    for i in range(0,3) :
        if(a[i]>b[i]):
            alice+=1
        if(a[i]<b[i]):
            bob+=1
    results=[]
    results.append(alice)
    results.append(bob)
    return results

    
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = map(int, raw_input().rstrip().split())

    b = map(int, raw_input().rstrip().split())

    result = compareTriplets(a, b)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
