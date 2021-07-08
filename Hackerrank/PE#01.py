import math
def find(num,n) :
   return ((num//n)*((num//n)+1)//2)*n
for _ in range(int(input())):
    num=int(input())-1
    print(int(find(num,3)+find(num,5)-find(num,15)))
