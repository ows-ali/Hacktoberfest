#Leonardo's Prime Factors

u=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47]

for _ in range(int(input())):
 n=int(input())
 c=0
 pr=1

 for t in u:
    pr=pr*t
    if(pr<=n):
        c=c+1
        continue
    
 print(c)