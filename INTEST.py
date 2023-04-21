https://www.codechef.com/submit/INTEST




(n,k)=map(int,input().split(" "))
ans=0
for i in range(n):
    x=int(input())
    if x % k==0:
        ans+=1

print(ans)
