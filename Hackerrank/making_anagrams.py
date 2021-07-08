from collections import Counter
st1=Counter([str(x) for x in input().strip()])
st2=Counter([str(x) for x in input().strip()])
d1=st1-st2
d2=st2-st1
print(sum(d1.values())+sum(d2.values()))