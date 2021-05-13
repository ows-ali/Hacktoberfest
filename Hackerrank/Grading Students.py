#!/bin/python
 
from __future__ import print_function
 
import os
import sys
 
#
# Complete the gradingStudents function below.
#
def gradingStudents(grades):
    res = []
    for grade in grades:
        if grade >= 38 and grade % 5 >= 3:
            grade = grade + 5 - (grade % 5)
        res.append(grade)
    return res
 
if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')
 
    n = int(raw_input())
 
    grades = []
 
    for _ in xrange(n):
        grades_item = int(raw_input())
        grades.append(grades_item)
 
    result = gradingStudents(grades)
 
    f.write('\n'.join(map(str, result)))
    f.write('\n')
 
    f.close()