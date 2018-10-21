m=input()
arr=m.split(" ")
arrInt=list(map(int,arr))
sum=0
for i in arrInt:
    sum+=i
print(sum-max(arrInt),sum-min(arrInt))

