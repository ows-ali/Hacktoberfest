l=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
x=input()
y=len(x)
c=0
for i in range(0,26):
    for j in range(0,y):
        if l[i]==x[j]:
            c=c+1
            break
if c<26:
    print('not panagram')
else:
    print('panagram')
