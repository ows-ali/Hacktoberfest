def is_prime(number):
    if (number < 2):
        return False

    # check if number is divisible by 2 to number/2 +1 so number of iterations are reduced
    # the largest number that can divide the number is its half
    for divisor in range(2, number // 2 + 1):
        if number % divisor == 0:
            return False

    return True


print(is_prime(102))
print(is_prime(10))
