#https://www.codechef.com/problems/MDL

import statistics 
N=int(input())
for i in range(0,N):
    a=int(input("No. of elements: "))
    ls=[]
    for j in range(0,a):
        b=int(input())
        ls.append(b)
    s=statistics.median(ls)
    if s in ls:
        ls.remove(s)
print(ls)
