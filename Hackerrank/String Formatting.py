# String Formatting 
# Question: https://www.hackerrank.com/challenges/python-string-formatting/problem

def print_formatted(n):

    width = len(bin(n)[2:])
    for i in range(1,n+1):
        o=str(oct(i))
        h=str(hex(i))
        b=str(bin(i))
        j=str(i)
        print(j.rjust(width),o[2:].rjust(width),h[2:].upper().rjust(width),b[2:].rjust(width))
        #print("{:2} {:2} {:2} {:2}".format(j,o[2:],h[2:].upper(),b[2:]))


if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
