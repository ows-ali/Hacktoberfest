#Solution for the hacker rank python challenge - Python If-Else
#https://www.hackerrank.com/challenges/py-if-else/problem?h_r=next-challenge&h_v=zen

import math
import os
import random
import re
import sys


if __name__ == '__main__':
    n = int(input())

    if (n % 2 == 1):
        print("Weird")
    elif (n >= 2 and n <=5):
        print("Not Weird")
    elif (n >= 6 and n <= 20):
        print("Weird")
    elif (n > 20):
        print("Not Weird")