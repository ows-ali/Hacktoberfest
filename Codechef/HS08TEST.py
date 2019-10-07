# https://www.codechef.com/problems/HS08TEST

x = int(input())                #withdrawal
y = round(float(input()), 2)    #balance

print(x,y)

if x %5 == 0:
    y = y-x-0.50
    print(f"{y:.2f}")
    
else:
    print(f"{y:.2f}")
