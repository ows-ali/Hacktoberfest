t=int(input())
for i in range(t):
    x,y,k=list(map(int,input().split()))
    if (int((x+y)/k))%2==0:
        print("Chef")
    else:
        print("Paja") 