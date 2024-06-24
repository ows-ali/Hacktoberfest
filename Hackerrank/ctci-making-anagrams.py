# https://www.hackerrank.com/challenges/ctci-making-anagrams/problem

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the makeAnagram function below.
def makeAnagram(a, b):
    # Using a 2x26 matrix ("histogram"), the first row represting string a,
    # the second string b, and in each cell the number of appearances of each
    # of the 26 characters in the English alphabet.
    hist = [[0]*26 for i in range(2)]
    for c in a:
        hist[0][ord(c) - ord('a')] += 1
    for c in b:
        hist[1][ord(c) - ord('a')] += 1
    count = 0
    # Counting the differences between the number of appearances of each
    # character.
    for i in range(26):
            if hist[0][i] != hist[1][i]:
                count += abs(hist[0][i] - hist[1][i])
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = input()

    b = input()

    res = makeAnagram(a, b)

    fptr.write(str(res) + '\n')

    fptr.close()
