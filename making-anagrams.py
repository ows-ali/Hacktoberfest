def makingAnagrams(s1, s2):
    s = set(s1 + s2)
    return sum([abs(s1.count(word) - s2.count(word)) for word in s])

s1 = input()
s2 = input()
result = makingAnagrams(s1, s2)
print(result)

