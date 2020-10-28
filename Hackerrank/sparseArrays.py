#URL: https://www.hackerrank.com/challenges/sparse-arrays/problem

def matchingStrings(strings, queries):
    dct = {}
    ans = []
    for string in strings:
        if string in dct:
            dct[string]+=1
        else:
            dct[string]=1
    q = len(queries)
    for i in range(q):
        ans.append(dct.get(queries[i],0))
    return ans
