#!/usr/bin/py
from datetime import date
 
def calculateHackos(actual, expected):
    actual_date = date(actual[2], actual[1], actual[0])
    expected_date = date(expected[2], expected[1], expected[0])
     
    if actual_date.year > expected_date.year: return 10000
    if actual_date.year < expected_date.year: return 0
    if actual_date.month > expected_date.month: return (actual_date.month - expected_date.month) * 500
    if actual_date.month < expected_date.month: return 0
    if actual_date.day > expected_date.day: return (actual_date.day - expected_date.day) * 15
    return 0   
 
if __name__ == '__main__':
    actual = map(int, raw_input().split())
    expected = map(int, raw_input().split())
    print calculateHackos(actual, expected)