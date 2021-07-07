#Link to problem: https://www.codechef.com/problems/SEGM01

l = []

for i in range(int(input())):
    a = input()
    
    if a.count('0') == 0:
        l.append('YES')
    elif a.count('1') == 0:
        l.append('NO')
    else:
        a = a[a.index('1')::]
        i1 = a.index('1')
        x = a[::-1]
        i2 = x.index('1')
        a = a[i1:len(a)-i2:]
        
        if a.count('0') == 0:
            l.append('YES') 
        else:
            l.append('NO') 

for i in l:
    print(i)
