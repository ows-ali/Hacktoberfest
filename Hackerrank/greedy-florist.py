#!/bin/python

import sys

def getMinimumCost(n, k, c):
    c =  sorted(c,reverse=True)
    if k>n:
        k = n
    i,cost,K=0,0,-1
    while i<n:
        K+=1
        j = 0
        while i+j<n and j<k:
            cost += (K+1)*c[i+j]
            j+=1
        i +=k
    return cost
            
            
        

n, k = raw_input().strip().split(' ')
n, k = [int(n), int(k)]
c = map(int, raw_input().strip().split(' '))
minimumCost = getMinimumCost(n, k, c)
print(minimumCost)
