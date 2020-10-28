#URL: https://www.hackerrank.com/challenges/mars-exploration/problem

def marsExploration(s):
    n = len(s)
    cnt = 0
    for i in range(0,n,3):
        if s[i]!="S":
            cnt+=1
        if s[i+1]!="O":
            cnt+=1
        if s[i+2]!="S":
            cnt+=1
    return cnt
