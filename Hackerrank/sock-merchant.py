#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    socks = {}
    pairs = 0

    for sock in range(len(ar)):
        if ar[sock] in socks and socks[ar[sock]] == 1:
            pairs += 1
            socks[ar[sock]] -= 1
        else:
            socks[ar[sock]] = 1
    return pairs
        
    



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
