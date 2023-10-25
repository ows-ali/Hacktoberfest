# Given a time in -hour AM/PM format,
# convert it to military (24-hour) time.
#programmed in python3

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#


def timeConversion(s):
    # Write your code here
    p = s[-2:]
    h = s[:2]
    if p == 'AM':
        if h == '12':
            h = '00'
    else:
        if h != '12':
            h = str(int(h) + 12)
    
    return h + s[2:-2]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
