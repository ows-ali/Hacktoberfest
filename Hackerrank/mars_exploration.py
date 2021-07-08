import sys
s = str(input())
l=len(s)

c=0
st=''.join(['SOS']*int(l/3))
s1=list(s)
s2=list(st)      


for a, b in zip(s1, s2):
            if a != b:
                c=c+1
print(c)
