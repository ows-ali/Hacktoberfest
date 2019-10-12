# cook your dish here
t=int(input())
for i in range(t):
    s = input()
    s = s.split()
    n= int(s[0])
    k = int(s[1])
    if(n%k**2==0):
        print("NO")
    else:
        print("YES")