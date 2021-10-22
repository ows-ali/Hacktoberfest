class RotationMatrix(object):
    def __init__(self, M, N, entries):
        self.M, self.N = M, N
        self.entries = dict(entries)
        self.tier_index = self._create_tier_index()
        
    def __str__(self):
        string = ""
        for i in range(self.M):
            for j in range(self.N):
                sep = " " if j < self.N-1 else "\n"
                string += str(self.entries[(i,j)]) + sep
        return string
   
    def rotate_matrix(self, R):
        for index in self.tier_index:
            tier_copy = {key:self.entries[key] for key in index}
            for list_index, key in enumerate(index):
                rkey = index[(list_index + R + 1) % len(index) - 1]
                self.entries[rkey] = tier_copy[key]
        
    def _create_tier_index(self):
        row, col, tier_index = 0, 0, []
        directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        while self.M - 2 * row > 0 and self.N - 2 * col > 0:
            i, j = row, col
            tier_list = []
            for move in directions:
                while True:
                    if i + move[0] > self.M - row - 1 or i + move[0] < row or \
                    j + move[1] > self.N - col - 1 or j + move[1] < col:
                        break
                    else:
                        i, j = i + move[0], j + move[1]
                    tier_list.append((i, j))
            tier_index.append(tier_list)
            row, col = row + 1, col + 1
        return tier_index

M, N, R = [int(value) for value in input().split()]
mat = {}
for i in range(M):
    values = input().split()
    for j in range(N):
        mat[(i,j)] = int(values[j])
A = RotationMatrix(M, N, mat)
A.rotate_matrix(R)
print(A)
