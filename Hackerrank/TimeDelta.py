#!/bin/python3

import os
import datetime

# Complete the time_delta function below.
def time_delta(t1, t2):
    month = {'Jan':1,'Feb':2,'Mar':3,'Apr':4,'May':5,'Jun':6,'Jul':7,'Aug':8,'Sep':9,'Oct':10,'Nov':11,'Dec':12}

    dmy = t1.split()[1:4]
    hms = list(map(int,t1.split()[4].split(':')))
    zone = t1.split()[5]
    z1 = [int(zone[1:3]),int(zone[3:5])]
    if "-" in zone:
        z1 = [-x for x in z1]
    time1 = datetime.datetime(int(dmy[2]),month[dmy[1]],int(dmy[0]),hms[0],hms[1],hms[2])

    dmy = t2.split()[1:4]
    hms = list(map(int,t2.split()[4].split(':')))
    zone = t2.split()[5]
    z2 = [int(zone[1:3]),int(zone[3:5])]
    if "-" in zone:
        z2 = [-x for x in z2]
    time2 = datetime.datetime(int(dmy[2]),month[dmy[1]],int(dmy[0]),hms[0],hms[1],hms[2])

    if time1>time2:
        time = time1-time2
        z = [z1[i] - z2[i] for i in [0,1]]
    else:
        time = time2-time1
        z = [z2[i] - z1[i] for i in [0,1]]

    result = time.seconds + time.days*86400
    result -= z[0]*3600 + z[1]*60
    if result<0:
        result*=-1
    return str(result)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        t1 = input()
        t2 = input()

        delta = time_delta(t1, t2)

        fptr.write(delta + '\n')

    fptr.close()
