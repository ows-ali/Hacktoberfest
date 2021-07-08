k=int(input())
s=0
for _ in range(k):
    t=str(int(input()))
    s=s+int(t[:12])
print(str(s)[:10])
