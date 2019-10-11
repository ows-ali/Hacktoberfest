n,d = [int(s) for s in input().split(' ')]

A = [int(s) for s in input().split(' ')]

B = [0]*n
pointer = 1

d = d%n

c = 0
for i in range(n):
    pointer = (i-d) + n
    if(pointer >= n):
        pointer = c
        c+=1
    #print('p: ',pointer)
    B[pointer] = A[i]
    
for i in range(n):
    print(B[i] ,end =' ')


    