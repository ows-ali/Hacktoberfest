# Enter your code here. Read input from STDIN. Print output to STDOUT
if __name__ == "__main__":
    a = int(input())
    b = int(input())
    r = divmod(a, b)
    print(r[0])
    print(r[1])
    print(r)

