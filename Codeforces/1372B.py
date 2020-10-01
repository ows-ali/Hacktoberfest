# B. Omkar and Last Class of Math
# Read the comments below for the explanation of the solution to this problem
testCase = int(input())

# Beginning of the code
while testCase>0:
    element = int(input())
    i = 2
    a = 0
    b = 0
    check=1
    #Finding the least element that divides our number n completely
    while (i*i<=element):
        if (element%i==0):
            a = element // i
            b = element - a
            check = 0
            break
        i+=1
    # If the element is a prime no then we do the following
    if check==1:
        a = 1
        b = element - 1
    print(a,end=" ")
    print(b)

    testCase-=1
# End of code

# 	Explained Solution:
'''
Goal: We have to find two positive integers x and y which adds upto n i.e. x+y=n and LCM(x,y) has the least value.

Approach: For x and y to have the least LCM, we have to choose y such that it is a factor of x, i.e. y = Cx where C is some constant.

Also, x + y = n ----------------> equation 1
equation 1 can be re-written as:
x + Cx = n
=> x(1+C) = n
=> x = n/(1+C) -----------------------------> equation 2

Since x is an integer, we infer that x must be a multiple of n.
For: x+y =n and LCM(x,y) to be the least the best case would be when x=y. In that case C=1.
So, in equation 2 I want C to be as small as possible.
It means 1+C is the least value which completely divides the number n i.e. n%(1+C) == 0.

Therefore, 1+C can be found as the minimum no, which completely divides n.
This gives us x which is n/(1+C).
Now, we can calculate y as n-x.

Exception: In case no number can completely divide the number n, it is a prime number so, the best possible x+y for a prime number would be (1,n-1)

'''
# End of explanation 