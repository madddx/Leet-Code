class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        mod = 10**9 + 7
        down = [1] + [0] * (len(grid[0]) - 1)  # d: paths coming into each cell from above
        for row in grid:
            right = 0  # r: paths coming in from the left
            for j, mirror in enumerate(row):
                if mirror:  # a mirror swaps the flows
                    right, down[j] = down[j], right
                else:  # an empty cell merges them
                    right = down[j] = (right + down[j]) % mod
        return down[-1]
