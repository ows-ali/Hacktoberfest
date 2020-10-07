#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the climbingLeaderboard function below.
def climbingLeaderboard(scores, alice):
    alice.sort(reverse=True)
    scores=list(set(scores))+[-1]
    scores.sort(reverse=True)
    result=[]
    i=0;j=0
    while(len(result)!=len(alice)):
        if alice[j]>=scores[i]:
            result.append(i+1)
            j+=1
            continue
        i+=1
    result.reverse()
    return result


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    scores_count = int(input())

    scores = list(map(int, input().rstrip().split()))

    alice_count = int(input())

    alice = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(scores, alice)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
