t = int(input().strip())
for a0 in range(t):
    n,k = input().strip().split(' ')
    n,k = [int(n),int(k)]
    num = int(input())
    
    maxim=0
    for i in range(0,len(str(num))):
      
      prod=1
      t=str(num)[i:k+i]
      if len(t)==k:
        for u in t:
          prod=prod*int(u)
        if maxim<prod:
          maxim=prod
    print(maxim)
