def is_prime(number):
    if(number < 2):
        return False
        
    #check if number is divisible by 2 to number - 1
    for divisor in range(2, number):
        if number % divisor == 0:
            return False
            
    return True
    
if __name__=='__main__':
    n=int(input("Enter your number to be checked")
    a=is_prime(n)
    if a==True:
          print("Prime")
    else:
          print("Not prime")
#print(is_prime(15))
#print(is_prime(10))
