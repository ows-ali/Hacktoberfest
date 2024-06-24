#!/bin/python3

import math
import os
import random
import re
import sys

def staircase(n):
    for row in range(1,n+1):
        return ((n - row) * ' ' + row * '#')
n = int(input())
print(staircase(n))

