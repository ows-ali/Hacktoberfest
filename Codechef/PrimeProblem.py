# cook your dish here
n = int(input())
num =2


def isPrime(num) : 
   
    if (num <= 1) : 
        return False
    if (num <= 3) : 
        return True
 
    if (num % 2 == 0 or num % 3 == 0) : 
        return False
  
    i = 5
    while(i * i <= num) : 
        if (num % i == 0 or num % (i + 2) == 0) : 
            return False
        i = i + 6
  
    return True
    
while n>0:
    if(isPrime(num)):
        print(num)
        n=n-1
    num=num+1