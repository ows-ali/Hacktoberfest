a=int(input())

for i in range(a):
    b=list(map(int,input().split()))
    c=list(map(int,input().split()))
    d=[]
    for i in c:
        if i <= 0:
            d.append(1)
        else:
            d.append(0)
    
    f=d.count(1)
    if f >= b[1]:
        print("NO")
    else:
        print("YES")
