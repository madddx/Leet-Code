class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:

        graph = [[] for _ in range(n)]

        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * n

        def dfs(node):

            visited[node] = True

            vertices = 1

            degree_sum = len(graph[node])

            for nxt in graph[node]:
                if not visited[nxt]:
                    v, d = dfs(nxt)
                    vertices += v
                    degree_sum += d

            return vertices, degree_sum

        answer = 0

        for i in range(n):

            if visited[i]:
                continue

            vertices, degree_sum = dfs(i)

            edge_count = degree_sum // 2

            if edge_count == vertices * (vertices - 1) // 2:
                answer += 1

        return answer
