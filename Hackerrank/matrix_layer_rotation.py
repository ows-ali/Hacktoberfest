#!/bin/python

import math
import os
import random
import re
import sys

def getpoint(x, m, n):
    if x < n:
        return (0, x)
    elif x < m+n-1:
        return (x-n+1, n-1)
    elif x < m+n+n-2:
        return (m-1, n-x+m+n-3)
    else:
        return (m+m+n+n-x-4, 0)

def matrixRotation(matrix, m, n, r):
    m2 = [[y for y in x] for x in matrix]
    itermax = min([m, n])/2
    for it in xrange(itermax):
        curmax = 2*(m-2*it)+2*(n-2*it)-4
        for x in xrange(curmax):
            frmp = getpoint(x, m-2*it, n-2*it)
            top = getpoint((x-r)%curmax, m-2*it, n-2*it)
            m2[top[0]+it][top[1]+it] = matrix[frmp[0]+it][frmp[1]+it]
    for i in m2:
        print ' '.join(i)

if __name__ == '__main__':
    mnr = raw_input().rstrip().split()

    m = int(mnr[0])

    n = int(mnr[1])

    r = int(mnr[2])

    matrix = []

    for _ in xrange(m):
        matrix.append(raw_input().rstrip().split())

    matrixRotation(matrix, m, n, r)
