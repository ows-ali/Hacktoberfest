# https://www.codechef.com/problems/FLOW001

t = int(input("Input test cases:"))
array = []

for i in range(t):
    a, b = input().split(" ")
    array.append(int(a)+int(b))
    
print(*array)
    
