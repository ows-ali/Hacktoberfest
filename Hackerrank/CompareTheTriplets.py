alice = [int (i) for i in input().split()]
bob = [int (i) for i in input().split()]
pa , pb = [0, 0]
for i in range(3):
    if(alice[i] > bob[i]):
        pa+= 1
    elif(bob[i] > alice[i]):
        pb+=1
print(pa, pb)