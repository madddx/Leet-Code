class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])

        total = m * n
        k %= total

        ans = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):

                # index in 1D array (before rotation)
                oldIndex = i * n + j

                # index in 1D array (after rotation)
                newIndex = (oldIndex + k) % total

                # changing from 1D back to 2D
                newRow = newIndex // n
                newCol = newIndex % n

                ans[newRow][newCol] = grid[i][j]

        return ans
