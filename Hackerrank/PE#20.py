t=int(input())
for _ in range(t):
    n=int(input())
    su=0
    prod=1
    for i in range(1,n+1):
        prod=prod*i
   
    for k in str(prod):
        su=su+int(k)
    print(su)
