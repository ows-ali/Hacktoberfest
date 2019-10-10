n = int(input().strip())
s=str(input().strip())
k = int(input().strip())
for i in s:
 a=65 if i.isupper() else 97
 print((chr(a+(ord(i)-a+k)%26)) if i.isupper() or i.islower() else i ,end='')