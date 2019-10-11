def points(a,b,n):
    c=[]
    pt=0
    for i in range(n):
        pt+=(a[i]*20)
        pt-=(b[i]*10)
        if pt<0:
            c.append(0)
        else:
            c.append(pt)
        pt=0
    x=max(c)
    return x
t=int(input())
for i in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    
    print(points(a,b,n))