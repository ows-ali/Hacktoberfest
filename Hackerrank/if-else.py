https://www.hackerrank.com/challenges/py-if-else/problem?isFullScreen=true

#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    n = int(input().strip())

if n%2 != 0: # divide input number by 2 / if not equal to 0, number is odd
    print("Weird")
elif n%2 ==0 and n >2 and n<5 or n>20: # if equal to 0, number is even
    print("Not Weird")
else:
    print("Weird")
