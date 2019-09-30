def AddMaxTwo(a, b, c):
    x = a + b
    y = b + c
    z = a + c
    print(x,y,z)
    if(x > y > z or x > z > y):
        print(x)
    if(y > x > z or y > z > x):
        print(y)
    if(z > x > y or z > y > x):
        print(z)    




a = int(input("Please enter 1st number"))
b = int(input("Please enter 2nd number"))
c = int(input("Please enter 3rd number"))

AddMaxTwo(a, b, c)