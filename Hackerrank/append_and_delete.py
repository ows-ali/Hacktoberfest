s = str(input().strip())
t = str(input().strip())
k = int(input().strip())

def common_start(s1, s2):
    """ returns the longest common substring from the beginning of s1 and s2 """
    
    for a, b in zip(s1, s2):
            if a == b:
                yield a
            else:
                return
c=(list(common_start(s,t)))
l=len(c)

if (len(s)+len(t)-2*len(c)) > k:
    print("No")
elif (len(s)+len(t)-2*len(c))%2 == k%2:
    print("Yes")
elif(len(s)+len(t)<k):
    print("Yes")
else :
    print("No")