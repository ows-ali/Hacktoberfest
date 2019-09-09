def gcd(a,b):
    if(b==0):
        return a
    return gcd(b,a%b)
t=input();
for i in range(t):
    a,b,n=map(int,raw_input().split())
    if(a==b):
        res=pow(a,n,1000000007)
        res=res+pow(b,n,1000000007)
        res=res%(1000000007)
        print res
        continue
    res=pow(a,n,a-b)
    res=res+pow(b,n,a-b)
    res=res%(a-b)
    print gcd(a-b,res)
