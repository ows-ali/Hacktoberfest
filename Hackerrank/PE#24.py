from math import factorial
n=int(input())
def perm(n,s):
  if len(s)==1 : return s
  q,r=divmod(n,factorial(len(s)-1))
  return s[q]+perm(r,s[:q]+s[q+1:])

for _ in range(n):
 
   s='abcdefghijklm'
   print(perm(int(input())-1,s))
