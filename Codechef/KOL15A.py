t = int(input())

for num in range(t):
    
    user = input()
    
    add = 0
    
    for i in range(len(user)):
        if user[i].isdigit() == True:
            globals()['add'] = globals()['add'] + int(user[i])
        
    print(add)
