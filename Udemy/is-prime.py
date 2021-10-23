def is_prime(number):
    if(number < 2):
        return False
        
    #check if number is divisible by 2 to - 1
    for divisor in range(2, number):
        if number % divisor == 0:
            return False
            
    return True
    
print(is_prime(15))
print(is_prime(10))
