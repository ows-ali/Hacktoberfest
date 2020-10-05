#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the dayOfProgrammer function below.
def dayOfProgrammer(year):
    leap=[31,29,31,30,31,30,31,31,30,31,30,31]
    notLeap=[31,28,31,30,31,30,31,31,30,31,30,31]
    uni=[31,15,31,30,31,30,31,31,30,31,30,31]
    m=0
    tot=0
    month=day=0
    date=""
    if year%400==0:
        m=1
    if year%4==0:
        if year%100!=0:
            m=1
    if year<1917:
        if year%4==0:
            m=1
    if year==1918:
        for i in range(len(uni)):
            if (tot+uni[i])<256:
                tot=tot+uni[i]
            else:
                day=256-tot
                month=i+1
                if month<=10:
                    month=str("0{}".format(month))
                date="{}.{}.{}".format(day,month,year)
                return date
    if m!=1:
        for i in range(len(notLeap)):
            if (tot+notLeap[i])<256:
                tot=tot+notLeap[i]
            else:
                day=256-tot
                month=i+1
                if month<=10:
                    month=str("0{}".format(month))
                date="{}.{}.{}".format(day,month,year)
                return date
    else:
        for i in range(len(leap)):
            if (tot+leap[i])<256:
                tot=tot+leap[i]
            else:
                day=256-tot
                month=i+1
                if month<=10:
                    month=str("0{}".format(month))
                date="{}.{}.{}".format(day,month,year)
                return date



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    year = int(input().strip())

    result = dayOfProgrammer(year)

    fptr.write(result + '\n')

    fptr.close()
