t = int(input().strip())
for a0 in range(t):
    n = int(input())
    i=2
    lprime=2
    while i*i<=n:
        while n%i ==0:
          lprime=i
          n=n//i
        i=i+1
    if n>lprime:
      lprime=n
    print(lprime)
