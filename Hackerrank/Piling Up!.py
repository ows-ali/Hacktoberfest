n = int(input())

for i in range (n):
    input()
    length = list(map(int, input().split()))
    l = len(length) 
    a = 0
    while a < l-1 and length[a]>=length[a+1]:
        a = a+1
    while a< l-1 and length[a]<=length[a+1]:
        a= a + 1
    if a == l-1:
        print ("Yes")
    else :
        print ("No")

