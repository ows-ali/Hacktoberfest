#!/bin/python3
"""

 Created by akiselev on 2019-05-22
 
 
"""

import os

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    matched=0
    print(list(set(ar)))
    for color in list(set(ar)):
        print(ar.count(color))
        matched+=ar.count(color)//2

    return matched
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()
