# Sales By Match Hackerrank Problem -> https://www.hackerrank.com/challenges/sock-merchant/problem
# Submited by Denys Menfredy -> github.com/DenysMenfredy

def sockMerchant(n, ar):
    return sum([ar.count(el) // 2 for el in set(ar)])

if __name__ == '__main__':
    n = int(input().strip())
    ar = list(map(int, input().strip().split(' ')))
    result = sockMerchant(n, ar)
    print(result)