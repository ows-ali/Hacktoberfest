from math import factorial
s=0


for i in range(19,int(input())):
    su=0
    for k in str(i):
        su=su+factorial(int(k))
    if su % i == 0 :
     s=i+s
print(s)
