from itertools import groupby
print(*[(len(list(c)), int(k)) for k, c in groupby(input())])
