def sumw(l):
    l=[str(j) for j in l]
    b=[]
    for i in range(len(l)):
        l[i]=list(l[i])
        l[i]=[int(j) for j in l[i]]
        a=l[i]
        a=sum(a)
        b.append(a)
    return b

f=int(input())
for m in range(f):
    r=int(input())
    a=list(map(int,input().split()))
    e=[]
    for i in range(r):
        for j in range(r):
            if i!=j:
                t=a[i]*a[j]
                e.append(t)
    e=list(set(e))
    w=sumw(e)
    print(max(w))