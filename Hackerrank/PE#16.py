for _ in range(int(input())):
    p=int(input())
    n=2**p
    su=0
    for k in str(n):
        su=su+int(k)
    print(su)
