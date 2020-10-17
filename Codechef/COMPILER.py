try:
    t = int(input())
    maxim = []
    for i in range(t):
        nall = input().split()
        n = str(nall[0])
        count = 0
        opened = 0
        pos = 0
        for j in range(len(n)):
            if(n[j] == '<'):
                count +=1
            elif(n[j] == '>'):
                count -=1
            if(count < 0):
                break
            if(count == 0):
                pos = j + 1
        maxim.append(pos)
        
    for elem in maxim:
        print(elem) 
except:
    pass
