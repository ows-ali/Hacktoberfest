#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the staircase function below.
def staircase(n):
    for row in range(1,n+1):
        return ((n - row) * ' ' + row * '#')
n = int(input())
print(staircase(n))
