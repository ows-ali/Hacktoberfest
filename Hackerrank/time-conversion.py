#!/bin/python3

# Given a time in -hour AM/PM format,
# convert it to military (24-hour) time.

import math
import os
import random
import re
import sys


def timeConversion(s):
    # Write your code here
    dots = s.index(":")
    hour = s[0:dots]
    am_pm = s[-2:]

    
    if(am_pm == "PM" and not int(hour) == 12):
        new_hour = str(int(hour) + 12)
            
    elif(am_pm == "AM" and  int(hour) == 12):
        new_hour = "00"
    
    else:
        new_hour = hour

    return new_hour + s[2:8]

# test cases 
# print( timeConversion("12:05:45AM") + " = 00:05:45")
# print( timeConversion("01:05:45AM") + " = 01:05:45")
# print( timeConversion("02:05:45AM") + " = 02:05:45")
# print( timeConversion("05:05:45AM") + " = 05:05:45")
# print( timeConversion("08:05:45AM") + " = 08:05:45")
# print( timeConversion("10:05:45AM") + " = 10:05:45")
# print( timeConversion("11:05:45AM") + " = 11:05:45")
# print( timeConversion("12:05:45PM") + " = 12:05:45")
# print( timeConversion("01:05:45PM") + " = 13:05:45")
# print( timeConversion("02:05:45PM") + " = 14:05:45")
# print( timeConversion("05:05:45PM") + " = 17:05:45")
# print( timeConversion("07:05:45PM") + " = 19:05:45")
# print( timeConversion("10:05:45PM") + " = 22:05:45")
# print( timeConversion("11:05:45PM") + " = 23:05:45")
# print( timeConversion("12:00:00AM") + " = 00:00:00")