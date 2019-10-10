import math

def p_sieve(n):
    sieve=[True]*(n+1)
    sieve[0]=False
    sieve[1]=False
    global primes
    primes={}
    for i in range(2,int(math.sqrt(n))+1):
        
        
        for p in range(i*i,n+1,i):
            sieve[p]=False
    c=1
    for j in range(n+1):
            if sieve[j]==True:
                
                primes[c]=j
                c=c+1
        
    return primes

p_sieve(200000)
for _ in range(int(input())):
    print(primes.get(int(input())))
