t=int(input())
for _ in range(t):
    n=int(input())
    a=input()
    b=input()
    d=[[1] for _ in range(26)]
    s=0
    for i in range(n):
        #print(a[i],b[i])
        if(b[i]>a[i]):
            s=1
            break
        elif(a[i]>b[i]):
            if(b[i] in a):
                d[ord(b[i])-97].append(i)
                d[ord(b[i])-97][0]+=1
                #print(d)
            else:
                s=1
                break
    if(s==1):
        print(-1)
    else:
        #print(d)
        c=[i for i in range(26) if(len(d[i])>1)]
        print(len(c))
        for j in range(25,-1,-1):
            if(len(d[j])>1):
                d[j].insert(1,a.index(chr(j+97)))
                for k in d[j]:
                    print(k,end=' ')
                print(' ')
