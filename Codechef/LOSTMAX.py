t=int(input())
for i in range(t):
    a=list(map(int,input().split()))
    b=len(a)-1
    a.remove(b)
    print(max(a))