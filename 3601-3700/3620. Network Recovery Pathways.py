from collections import deque

class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)
        graph = [[] for _ in range(n)]
        indegree = [0] * n
        max_cost = 0

        for u, v, w in edges:
            graph[u].append((v, w))
            indegree[v] += 1
            max_cost = max(max_cost, w)

        # Topological sort
        topo, dq = [], deque(i for i in range(n) if indegree[i] == 0)
        deg = indegree[:]
        while dq:
            u = dq.popleft()
            topo.append(u)
            for v, w in graph[u]:
                deg[v] -= 1
                if deg[v] == 0: dq.append(v)

        def check(limit: int) -> bool:
            INF = float('inf')
            dp = [INF] * n
            dp[0] = 0
            for u in topo:
                if dp[u] == INF: continue
                if u != 0 and u != n - 1 and not online[u]: continue
                for v, w in graph[u]:
                    if w < limit: continue
                    if v != n - 1 and not online[v]: continue
                    dp[v] = min(dp[v], dp[u] + w)
            return dp[n - 1] <= k

        lo, hi, ans = 0, max_cost, -1
        while lo <= hi:
            mid = (lo + hi) // 2
            if check(mid): ans = mid; lo = mid + 1
            else: hi = mid - 1

        return ans
