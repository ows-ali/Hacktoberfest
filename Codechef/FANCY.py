c=int(input())
for i in range(c):
    a=input()
    b=a.split()
    if "not" in b:
        print("Real Fancy")
    else:
        print("regularly fancy")