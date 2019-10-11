a=input()
b=a.split()
c=list(int(c) for c in b)
e=sorted(c)
for i in range(len(c)):
    print(e[i])
print("")
for i in range(len(c)):
    print(c[i])