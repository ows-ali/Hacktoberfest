class Solution:
    #description: Given an integer n, return the number of trailing zeroes in n!.
    def trailingZeroes(self, n: int) -> int:
        nFactorial = self.factorial(n)
        total = 0
        while nFactorial%10 == 0 and nFactorial > 0:
            total += 1
            nFactorial = nFactorial//10
        return total
    
    def factorial(self, n: int) -> int:
        total = 1
        while n >= 2:
            total = total*n
            n -= 1
        return total
