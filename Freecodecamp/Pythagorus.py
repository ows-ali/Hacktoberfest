
#/// simple little program to test whether your triangle is a right angle triangle or not

sideOne = input("What is the length of the hypothenuse: ")
sideTwo = input("What is the length of the second side: ")
sideTwo = input("What is the lenght of the third side: ")

def calcPythagorian(sideH,sideA,sideO):
    hypothenuseSquare = float(sideH) ** 2
    othersidesquared = (float(sideA) ** 2) + (float(sideO) ** 2)

    if hypothenuseSquare = othersidesquared:
        true
    else:
        false

print(calcPythagorian(sideOne,sideTwo,sideThree))