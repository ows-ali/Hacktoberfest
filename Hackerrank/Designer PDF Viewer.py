#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the designerPdfViewer function below.
def designerPdfViewer(h, word):
   
    d={}
    p=97
    s=[]
    for i in h:
        d[chr(p)]=i
        p+=1
    wr_len=len(word)
    l=list(word)
    for i in l:
        s.append(d[i])
    m=max(s)
    fin_ans= m * len(word)
    print(fin_ans)    
    

if __name__ == '__main__':
    
    h = list(map(int, input().rstrip().split()))
    word = input()
    result = designerPdfViewer(h, word)

    
