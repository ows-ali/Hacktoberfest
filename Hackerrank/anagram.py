from collections import Counter
t=int(input())

for _ in range(t):
  a=[]
  
  st=str(input().strip())
  if(len(st)%2!=0):
        print(-1)
        continue
  else:
    c=0
    a.append(st[:int(len(st)/2)])
    
    a.append(st[int(len(st)/2):])
    diff=Counter(a[0])-Counter(a[1])
    
    print(sum(diff.values()))
