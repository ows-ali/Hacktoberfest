t=int(input())
for _ in range(t):
  m,n = map(int,input().split())
  f=0
  if(m==1):
    print(-1)
  else:
    for i in range(n,m*2):
      if(i%n == 0):
        print(i)
        f=1
        break
    if not f:
      print(-1)
  
