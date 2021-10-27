
p,d,m,s = [ int(i) for i in str(input()).split(" ")]

#print( p, m, d, s)


sm = p
cnt = 0
#arr = [p]
while s >= p:
    #print(p)
    
    s -= p
    p = max([p-d, m])
    cnt +=1
   
    #print("sum: ", sm)

print(cnt)