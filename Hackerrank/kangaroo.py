#!/bin/python3
import os

# Complete the kangaroo function below.
def kangaroo(x1, v1, x2, v2):
    if v1 == v2: return "NO"  # parallel lines never cross
    n = (x2 - x1)/(v1- v2)  # number of steps where lines intersect
    return "YES" if n.is_integer() and n>=0 else "NO" # if intersect is a natural number

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    x1V1X2V2 = input().split()
    x1 = int(x1V1X2V2[0])
    v1 = int(x1V1X2V2[1])
    x2 = int(x1V1X2V2[2])
    v2 = int(x1V1X2V2[3])
    result = kangaroo(x1, v1, x2, v2)
    fptr.write(result + '\n')
    fptr.close()
