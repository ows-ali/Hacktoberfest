"""
https://www.hackerrank.com/challenges/sherlock-and-squares/problem
"""
import math
test_cases = int(input())
def cal(test_cases):
    result = 0
    a, b = input().split()
    sqrta = math.ceil(math.sqrt(int(a)))
    sqrtb = math.floor(math.sqrt(int(b)))
    return (sqrtb - sqrta + 1)
for i in range(test_cases):
    print(cal(test_cases))
