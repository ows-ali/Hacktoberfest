from fractions import gcd
for _ in range(int(input())):
    l,b=[int(t) for t in input().strip().split(' ')]
     
    
    print((l*b)//gcd(l,b)**2)
    