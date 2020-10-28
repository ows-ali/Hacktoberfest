#URL: https://www.hackerrank.com/challenges/two-characters/problem
def alternate(l, s):

    chars = list(set(s))
    n = len(chars)
    maxlen = 0
    #print(chars)
    for i in range(n):
        for j in range(i+1,n):
            ch1 = chars[i]
            ch2 = chars[j]
            tempans = ""
            ansl = 0
            f = True
            for ch in s:
                if ch ==ch1:
                    if (ansl==0) or tempans[-1]==ch2:
                        tempans+=ch
                        ansl+=1
                    else:
                        f= False
                        break
                elif ch == ch2:
                    if (ansl==0) or tempans[-1]==ch1:
                        tempans+=ch
                        ansl+=1
                    else:
                        f=False
                        break
            if f:
                maxlen = max(maxlen, ansl)
    return maxlen
