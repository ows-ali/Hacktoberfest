# Solution to a problem in hackerrank: https://www.hackerrank.com/challenges/python-loops/problem?isFullScreen=true&h_r=next-challenge&h_v=zen
# the loop is supposed do deliver output if the input went wrong

if __name__ == '__main__':
    n = int(input())
    if n >= 1 and n <= 20:
        while n >= 1:
            print (n**2)
            n = n - 1
            #return i
    else:
     print ("number must be non-negative and smaller than 20")