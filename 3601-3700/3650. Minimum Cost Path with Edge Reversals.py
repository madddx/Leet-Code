import heapq

class Solution(object):
    def minCost(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        # Adjacency list for the augmented graph.
        # adj[u] contains tuples (v, cost) representing a directed edge u -> v.
        adj = [[] for _ in range(n)]
        
        for u, v, w in edges:
            # 1. The original directed edge u -> v with cost w
            adj[u].append((v, w))
            
            # 2. The switch at v can be used to reverse the incoming edge u -> v.
            # This creates a directed edge v -> u with cost 2 * w.
            adj[v].append((u, 2 * w))
        
        # Standard Dijkstra's algorithm
        dist = [float('inf')] * n
        dist[0] = 0
        min_heap = [(0, 0)] # (current_cost, node)
        
        while min_heap:
            current_cost, u = heapq.heappop(min_heap)
            
            # If we reached the target node, return the cost immediately.
            # Since we use a min-heap, the first time we pop the target, 
            # we have found the shortest path.
            if u == n - 1:
                return current_cost
            
            # Optimization: if we have already found a better path to u, skip.
            if current_cost > dist[u]:
                continue
            
            for v, w in adj[u]:
                new_dist = current_cost + w
                if new_dist < dist[v]:
                    dist[v] = new_dist
                    heapq.heappush(min_heap, (new_dist, v))
        
        # If the loop finishes without reaching the target, return -1
        return -1
