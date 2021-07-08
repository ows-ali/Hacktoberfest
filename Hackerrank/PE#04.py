sieve = [False] * (1000000)
def pal():
  for p in [100001*a + 10010 * b +1100 *c for a in range(1,10) for b in range(0,10) for c in range(0,10)]:
    sieve[p]=True
 
pal()

for _ in range(int(input())):
    num=int(input())
    res=[]
    for i in range(999,99,-1):
     
       for j in range(i,99,-1):
           
                prod=i*j
                if prod%11==0:
                  if sieve[prod] and prod <num:
                   res.append(prod)
        
    print(max(res))

