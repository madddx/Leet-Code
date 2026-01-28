class Solution(object):
    def minCost(self, grid, k):
        """
        :type grid: List[List[int]]
        :type k: int
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        if k and grid[m - 1][n - 1] <= grid[0][0]:
            return 0
        mx = max(max(r) for r in grid)
        sufMinf = [float('inf')] * (mx + 2)
        minf = [float('inf')] * (mx + 1)
        f = [float('inf')] * (n + 1)
        for _ in range(k + 1):
            minf = [float('inf')] * (mx + 1)
            f = [float('inf')] * (n + 1)
            f[1] = -grid[0][0]
            for r in grid:
                for j, x in enumerate(r):
                    f[j + 1] = min(min(f[j], f[j + 1]) + x, sufMinf[x])
                    minf[x] = min(minf[x], f[j + 1])
            tmp = sufMinf[:]
            for i in range(mx, -1, -1):
                sufMinf[i] = min(sufMinf[i + 1], minf[i])
            if sufMinf == tmp:
                break
        return f[n]
