#URL: https://www.hackerrank.com/challenges/hackerrank-in-a-string/problem

def hackerrankInString(s):
    lst = ['h', 'a', 'c', 'k', 'e', 'r', 'r', 'a', 'n', 'k']
    l = 10
    i = 0
    for ch in s:
        if ch==lst[i]:
            i+=1
        if i>=10:
            break
    if i>=10:
        return "YES"
    return "NO"
