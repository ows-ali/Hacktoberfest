# A function to check whether all salaries are equal
def areAllEqual(array):
    s = set(array)
    if(len(s)==1):
        return True
    else:
        return False

# Main code starts here
testCases = int(input())
for x in range(testCases):
    moveCount=0
    salArray = []
    n = int(input())
    for j in range(n):
        element = int(input())
        salArray.append(element)
    print(salArray)
    
    #As long as the salries aren't equal, we'll reduce the max salary by 1
    while(areAllEqual(salArray)==False):
        maxElement=max(salArray)
        for x in range(len(salArray)):
            if(salArray[x]==maxElement):
                salArray[x]=salArray[x]-1
                moveCount+=1
        print(salArray)
    print(moveCount)

