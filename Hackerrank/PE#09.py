for _ in range(int(input())):
    n=int(input())
    d=[]
    for a in range(1,n//3):
        b=((a**2)-(a-n)**2) /(2*(a-n))
        c=n-a-b
        if a*a + b*b == c*c  and b>0 and c>0 and b==int(b):
          
            d.append(a*b*c)
    
    if len(d)==0 :
            print(-1)
    else:
            print(int(max(d)))
