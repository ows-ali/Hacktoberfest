#URL: https://www.hackerrank.com/challenges/simple-text-editor/problem

q = int(input())
stack = []
top=-1

for _ in range(q):
    query = input().split()
    if query[0]=="1":
        if top>=0:
            stack.append( stack[top]+query[1] )
        else:
            stack.append( query[1] )
        top+=1
    elif query[0]=="2":
        string = stack[top]
        k = int(query[1])
        l = len(string)-k
        stack.append(string[:l])
        top+=1

    elif query[0]=="3":
        k = int(query[1])
        print(stack[top][k-1])
    else:
        stack.pop()
        top-=1
