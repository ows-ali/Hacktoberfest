import math
def is_prime(n):
    if n% 2 ==0 and n>2:
        return False
    for i in range(3,int(math.sqrt(n))+1,2):
        if n%i==0:
            return False
    return True

d={}
sum=0
for n in range(3,1000001,2):
    if is_prime(n):
        sum=sum+n
        d[n]=sum+2


t=int(input())
for _ in range(t):
    n=int(input())

    for k in range(n,0,-1):
        if is_prime(k):
            print(d[k])
            break

