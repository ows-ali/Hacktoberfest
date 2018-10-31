#!/bin/python3

import sys

def angryChildren(k, arr):
    arr = sorted(arr)
    m = 1000000000
    for i in range(k-1,len(arr)):
        if arr[i]-arr[i-k+1]<m:
            m = arr[i]-arr[i-k+1]
    return m 

if __name__ == "__main__":
    n = int(input().strip())
    k = int(input().strip())
    arr = []
    arr_i = 0
    for arr_i in range(n):
       arr_t = int(input().strip())
       arr.append(arr_t)
    result = angryChildren(k, arr)
    print(result)

