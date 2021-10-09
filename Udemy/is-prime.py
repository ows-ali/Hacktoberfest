def is_prime(number):
    if(number < 2):
        return False
        
    #check if number is divisible by 2 to number - 1
    divisor=2
    while divisor*divisor <= number:
        if number % divisor == 0:
            return False
        divisor+=1
            
    return True
    
print(is_prime(15))
print(is_prime(10))
