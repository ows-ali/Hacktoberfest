# Problem link: https://www.hackerrank.com/challenges/compare-the-triplets/problem
# A resposta do probelma é a criação de uma função, que compare os elementes de dois array
# e segunindo algumas regras é gerado um novo array

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the compareTriplets function below.
def compareTriplets(a, b):
    i=[0,0]
    for elem in range(3):
        if a[elem] > b[elem]:
            i[0] += 1
        elif a[elem] < b[elem]:
              i[1] += 1
    return i

a = [3,85,2]
b = [10,2,50]
print("Teste-1")
print(compareTriplets(a,b))

a = [10,5,2]
b = [10,2,50]
print("Teste-2")
print(compareTriplets(a,b))