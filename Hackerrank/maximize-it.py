import itertools

(K, N) = map(int, raw_input().split())

L = list()
for i in range(K):
    l = map(int, raw_input().split())
    n = l[0]
    L.append(l[1:])
    assert len(L[i]) == n

S_max = 0
L_max = None

for l in itertools.product(*L):
    s = sum([x**2 for x in l]) % N

    if s > S_max:
        S_max = s
        L_max = l

print S_max