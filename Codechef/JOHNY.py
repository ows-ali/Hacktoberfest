
try:
    T=int(input())
    while(T):
        N=int(input())
        A=[int(i) for i in input().split()]
        k=int(input())
        s=A.pop(k-1)
        A.append(s)
       
        x=A[N-1]
        i=-1
        for j in range(N-1):
            if A[j]<=x:
                i=i+1
                A[i],A[j]=A[j],A[i]
        A[i+1],A[N-1]=A[N-1],A[i+1]
        print(i+2)
        T-=1
except Exception:
    pass
