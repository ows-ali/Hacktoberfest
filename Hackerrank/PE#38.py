n,k=[int(t) for t in input().split()]

for i in range(2,n+1):
    s=[]
    u=0
    length=0
    while(length<=k):

           
      s.append(str(i*(u+1)))
      #print(s)
      length=len(str(s[u]))+length
      #print(length)
      if(length+len(s[u])>k):
          break
      u=u+1
    
    
    
    s=''.join(s)
    
    if '0' not in s and len(set(s))==k and len(s)==k  :
        if(sum(int(x) for x in s)==36 or sum(int(x) for x in s)==45):
          print(i)
          #print()
          #print(s)
