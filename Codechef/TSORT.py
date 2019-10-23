# cook your dish here
t = input()
t = int(t)
l = []
while t > 0 :
    n = input()
    n = int(n)
    l.append(n)
    t = t-1
a = sorted(l)

for i in range(0,len(a)):
    print("{}".format(a[i]))
