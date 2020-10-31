# https://www.codechef.com/COLF2018/problems/APR105


def primes_method2(n1, n2):
    out = list()
    for num in range(n1, n2 + 1):
        if all(num % i != 0 for i in range(2, num)):
            out.append(num)
    return out
n1, n2 = map(int, raw_input().strip().split())

results = list()
out1 = primes_method2(n1, n2)
flag1 = 0
for i in out1:
    if str(i) == str(i)[::-1]:
        flag1 = 1
        results.append(i)

if flag1 == 0:
    print "-1"
else:
    print min(results)
