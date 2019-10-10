from itertools import permutations
def is_prime(nu):
    if nu<=1:
        return False
    if nu<=3:
        return True
    if nu%2==0 or nu%3==0:
        return False

    r=int(nu**0.5)
    i=5
    while(i<=r):
        if nu%i == 0 or nu%(i+2)==0:
            return False
        i=i+6
    return True

n=int(input())
for o in range(n):
    
    num=int(input())
    lnum=len(str(num-1))
    
    t=-1
    
    if(lnum==4):
        for k in permutations('4321',4):
            k=''.join(k)
            
            if int(k)<=num and is_prime(int(k))==1:
                t=k
                print(t)
                break
        if t is -1:
            print("-1")
                
    elif(lnum==7):
        for k in permutations('7654321',7):
            k=''.join(k)
            
            if int(k)<=num and is_prime(int(k))==1:
                t=k
                print(t)
                break
                
        if t is -1 :
            print("4231")
    
    elif 4<lnum<7:
        print("4231")
    elif 7<lnum<=10:
        print("7652413")
    else:
        print("-1")
