#input number of test cases
#for each input case, first line contains two space seperated intergers N and K
#second line contains N space seperated intergers
for _ in range(int(input())):
    N,K=input().split()
    N=int(N)
    K=int(K)
    A = list(map(int,input().split()))
    o=""
    for i in range(N):
        if A[i]<=K:
            o+="1"
            K-=A[i]
        else:
            o+="0"
    print(o)