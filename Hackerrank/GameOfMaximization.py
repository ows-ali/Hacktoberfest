

def pile_allocation():
    x = 0
    y = []
    while x < 3 or x > 10 ** 5:
        x = int(input())
        if x < 3 or x > 10 ** 5:
            print("invalid input")

    while x != len(y):
        y = input().split(" ")

        if len(y) > x:
            print("too many piles entered, please input again")
    return y

def main():
    y = pile_allocation()
    o = 0
    p = 0
    odd = True
    for i in range(len(y)-1):
        if int(y[i])< 0 or int(y[i])>10**3:
            print("invalid number of rocks per pile ")
            pile_allocation()
        current = int(y[i])
        if i+2 < len(y):
            comp = int(y[i+2])
            if odd:
                o += comp+current
                odd = False
            else:
                p += comp+current
                odd = True
        else:
            if odd:
                o += current
            else:
                p+= current
    return min(o,p)*2

if __name__ == '__main__':
    print(main())