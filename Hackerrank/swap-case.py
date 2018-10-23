#!/bin/python3

# Swaps case of all chars in provided string
def swap_case(s):
    formattedStr = "".join(map(swapChar, s))
    return formattedStr

def swapChar(char):
    if char.islower():
        return char.upper()
    else:
        return char.lower()