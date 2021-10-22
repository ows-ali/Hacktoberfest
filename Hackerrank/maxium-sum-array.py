import bisect

t = int(input())
for _ in range(t):
        n, m = map(int, input().split())
        a = list(map(int, input().split()))

        csum = [a[0] % m]
        for x in a[1:]:
                csum.append((csum[-1] + x) % m)

        seen = [0]
        mx = -1
        for s in csum:
                idx = bisect.bisect_left(seen, s)
                if idx < len(seen):
                        mx = max(mx, s, (s - seen[idx]) % m)
                else:
                        mx = max(mx, s)
                bisect.insort_left(seen, s)
                #print(seen)

        print(mx)
