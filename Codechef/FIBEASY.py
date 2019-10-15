# Code Chef
# Problem code: FIBEASY

f = [0, 1]


def generate_fib():
    for _ in range(60):
        f.append((f[-1] + f[-2]) % 10)


tc = int(input())
generate_fib()
for i in range(tc):
    n = int(input())
    n = n >> 1
    n = n | n >> 32
    n = n | n >> 16
    n = n | n >> 8
    n = n | n >> 4
    n = n | n >> 2
    n = n | n >> 1
    n %= 60
    print(f[n])
