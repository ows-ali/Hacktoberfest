# Problem Statement- https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem


def calculate(s):
    arr=[0]*26
    for i in s:
        if(i==" "):
            continue
        a=abs(97-ord(i))
        arr[a]+=1
    return arr


def compute(s):
    arr=calculate(s)
    b=max(arr)
    set_a=set(arr)
    if len(set_a)==2:
        return "YES"
    elif len(set_a)==3 and arr.count(1)==1:
        return "YES"
    elif b>2 and b-1 not in arr:
        return "NO"
    elif b-1!=0:
        c=arr.index(b)
        s=s[:c]+" "+s[c+1:]
        arr1=calculate(s)
        if max(arr1)==b:
            return "NO"
        else:
            return "YES"
    else:
        return "YES"

# input for the program 
s=input().strip()
print(compute(s))
