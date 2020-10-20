#!/bin/python3
import re

if __name__ == '__main__':
    N = int(input())
    test = re.compile("[a-z.]+@gmail\\.com")
    names = []
    for N_itr in range(N):
        firstNameEmailID = input().split()
        firstName = firstNameEmailID[0]
        emailID = firstNameEmailID[1]
        if test.match(emailID):
            names.append(firstName)
    for name in sorted(names):
        print(name)
