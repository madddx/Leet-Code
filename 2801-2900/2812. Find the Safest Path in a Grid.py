from collections import deque
import heapq


class Solution:
    def maximumSafenessFactor(self, grid: list[list[int]]) -> int:
        n = len(grid)
        if grid[0][0] or grid[n-1][n-1]:
            return 0
        queue = deque()
        dist = [[float('inf')] * n for _ in range(n)]

        for i in range(n):
            for j in range(n):
                if grid[i][j]:
                    queue.append((i, j))
                    dist[i][j] = 0

        while queue:
            i, j = queue.popleft()
            for r, c in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
                if 0 <= r < n and 0 <= c < n and dist[r][c] == float('inf'):
                    dist[r][c] = dist[i][j] + 1
                    queue.append((r, c))
        heap = []
        heapq.heappush(heap, (-dist[0][0], 0, 0))
        visited = set()
        while heap:
            d, i, j = heapq.heappop(heap)
            if i == j == n-1:
                return -d
            if (i, j) in visited:
                continue
            visited.add((i, j))
            for r, c in [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]:
                if 0 <= r < n and 0 <= c < n:
                    new_d = min(-d, dist[r][c])
                    heapq.heappush(heap, (-new_d, r, c))

        return 0
