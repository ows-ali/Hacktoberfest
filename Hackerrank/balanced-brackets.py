#!/bin/python3

import sys

def isBalanced(s):
    # Write your code here
    for i in range(len(s) // 2):
        s = s.replace("()", '')
        s = s.replace('[]', '')
        s = s.replace('{}', '')
        
    if len(s) == 0:
        return "YES"
    else:
        return "NO"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        s = input()

        result = isBalanced(s)

        fptr.write(result + '\n')

    fptr.close()
