def rec(i,j):
    if(j==0 or j==i):
            return 1
    else:
            return (rec(i-1,j-1) + rec(i-1,j))
def pt(n):
    l1 = list()
    l2 = list()
    for k in range(n):
        l1.append(int(rec(n-1,k)))
    return l1
    
n = int(input())
print(pt(n))
