def isPrime(n):
    count=0
    for i in range(2,n):
        if(n%i==0):
            count+=1
    if(count>0):
        return false
    else:
        return true
inp=int(input())
if(isPrime(inp)):
    print("Prime Number")
else:
    print("Not a Prime Number")
