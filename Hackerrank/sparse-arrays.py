N = int(raw_input())
strings = []
while len(strings) < N:
    p = raw_input()
    strings.append(p)
Q = int(raw_input())
queries = []
while len(queries)<Q:
    q = raw_input()
    queries.append(q)
count = 0
for t in queries:
    print(strings.count(t))