class Solution(object):
    def maxSideLength(self, mat, threshold):
        """
        :type mat: List[List[int]]
        :type threshold: int
        :rtype: int
        """
        if not mat or not mat[0]:
            return 0
        m, n = len(mat), len(mat[0])

        # Build 2D prefix sums
        ps = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m):
            row_sum = 0
            for j in range(n):
                ps[i + 1][j + 1] = mat[i][j] + ps[i][j + 1] + ps[i + 1][j] - ps[i][j]

        def square_sum(r, c, k):
            """Sum of k×k square with top-left at (r, c)."""
            return ps[r + k][c + k] - ps[r][c + k] - ps[r + k][c] + ps[r][c]

        ans = 0
        # Try to grow 'ans' greedily while scanning the grid
        for i in range(m):
            for j in range(n):
                # Attempt to extend to ans+1 if it fits and meets threshold
                while i + ans < m and j + ans < n and square_sum(i, j, ans + 1) <= threshold:
                    ans += 1
        return ans
"""
🚀 Optimized Approach (Prefix Sum + Greedy Growth)
Key idea

Build a 2D prefix sum so any square sum can be queried in O(1).
Scan the matrix once, and try to increase the current best side length ans whenever possible:

For each top-left (i, j), while the square of side ans + 1 fits within bounds and its sum ≤ threshold, increase ans.
Since ans only increases and never decreases across the entire scan, the total number of expansions is at most min(m, n).
This gives an amortized O(m·n) time complexity.



2D Prefix Sum Reminder
Let ps be (m+1) × (n+1) where:
ps[i+1][j+1] = mat[i][j] + ps[i][j+1] + ps[i+1][j] - ps[i][j]

Then the sum of the square with top-left (r, c) and side k:
sum = ps[r+k][c+k] - ps[r][c+k] - ps[r+k][c] + ps[r][c]

Why O(m·n)?

The nested loops visit each cell once (m·n).
The inner while increases ans globally—it can increase at most min(m, n) times overall.
Each sum check is O(1) using the prefix sums.
Thus total is O(m·n).

 Notes & Tips

If the matrix values or thresholds are large, use a wider integer type for prefix sums (e.g., long long in C++).
Space can be optimized slightly by computing row-wise and then cumulative sums, but the standard (m+1) × (n+1) prefix table is simple and fast.
This greedy growth pattern relies on the fact that if a (k+1) × (k+1) square exists starting at (i, j), then ans can increase—no need to recheck smaller sizes elsewhere.
"""
