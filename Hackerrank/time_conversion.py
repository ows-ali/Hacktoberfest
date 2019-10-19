#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    #
    # Write your code here.
    #
    period = s[-2:]

    hours, minutes, seconds = s[:-2].split(':')

    if period == "AM":
        if int(hours) == 12:
            return "00:{}:{}".format(minutes, seconds)
        return "{}:{}:{}".format(hours,minutes, seconds)
    else:
        if int(hours) == 12:
            return "{}:{}:{}".format(hours,minutes, seconds)
        return "{}:{}:{}".format(int(hours)+12,minutes, seconds)
        

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()
