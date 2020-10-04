def disemvowel(string):
    rep = string
    vowels = ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
    for vow in string:
        if vow in vowels:
            rep = rep.replace(vow, "")
    return rep

def disemvowelBetterSolution(s):
    return s.translate(None, "aeiouAEIOU")