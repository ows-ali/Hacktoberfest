for _ in range(int(input())):
    n,m,k=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    f=0;l=0
    for i in range(1,n+1):
        if i in a and i in b:
            f+=1
        elif i not in a and i not in b:
            l+=1
    print(f,l)

# Click on this link to solve:
# https://www.codechef.com/problems/VCS?tab=statement