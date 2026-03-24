class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        
        it_fwd = (elem for row in grid for elem in row)
        it_rev = (elem for row in reversed(grid) for elem in reversed(row))
        
        prefix = list(accumulate(it_fwd, lambda x, y: (x * y) % 12345, initial=1))
        suffix = list(accumulate(it_rev, lambda x, y: (x * y) % 12345, initial=1))

        m,n = len(grid), len(grid[0])
        for i,j in product(range(m), range(n)):
            k = i * n + j
            grid[i][j] = (prefix[k] * suffix[-k-2]) % 12345
        
        return grid
