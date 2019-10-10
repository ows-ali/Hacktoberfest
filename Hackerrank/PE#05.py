def factor(n):
    f, factors, prime_gaps = 1, [], [2, 4, 2, 4, 6, 2, 6, 4]
    if n < 1:
        return []
    while True:
        for gap in ([1, 1, 2, 2, 4] if f < 11 else prime_gaps):
            f += gap
            if f * f > n:  # If f > sqrt(n)
                if n == 1:
                    return factors
                else:
                    return factors + [(n, 1)]
            if not n % f:
                e = 1
                n //= f
                while not n % f:
                    n //= f
                    e += 1
                factors.append((f, e))

    return factors
for _ in range(int(input())):
  n=int(input())
  fact={2:0,3:0,5:0,7:0,11:0,13:0,17:0,19:0,23:0,29:0,31:0,37:0,41:0,43:0,43:0,47:0}
  pro=1
  for i in range(2,n+1):
     for k in factor(i):
       if k[1]>fact.get(k[0]):
         fact.update({k[0]:k[1]})
  for u in fact:
     if(fact[u]!=0):
       pro=pro*(u**fact[u])
  print(pro)
