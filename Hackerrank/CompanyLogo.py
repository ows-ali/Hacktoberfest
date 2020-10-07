#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    s = input()
    dic=dict()
    for x in s:
        if x in dic.keys():
            dic[x]+=1
        else:
            dic[x]=1
    keys=list(dic.keys())
    keys.sort()
    values=list(dic.values())
    values.sort(reverse=True)
    for i in range(3):
        for k in keys:
            if(dic[k]==values[i]):
                print("%s %d"%(k,values[i]))
                keys.remove(k)
                break
