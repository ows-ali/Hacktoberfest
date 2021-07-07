def is_prime(number):
    if(number < 2):
        return False
        
    #check if number is divisible by 2 to number - 1
    'for divisor in range(2, number):
    '    if number % divisor == 0:
    '        return False
            
    'return True
    '''SLIGHTLY faster method is to check from 2 to the square root of the number
        then break as soon as it is found NOT to be a prime.
    for divisor in range(2, int(number ** 0.5) + 1):
        if number % divisor == 0:
            return False
            break
    return True
    
print(is_prime(15))
print(is_prime(10))
