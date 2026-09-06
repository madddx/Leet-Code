class Solution:
    def numDistinct(self, s, t):
        n, m = len(s), len(t)
        memo = {}

        def solve(i, j):
            if j == m:
                return 1
            if i == n:
                return 0
            if (i, j) in memo:
                return memo[(i, j)]

            notTake = solve(i + 1, j)
            take = 0

            if s[i] == t[j]:
                take = solve(i + 1, j + 1)

            memo[(i, j)] = take + notTake
            return memo[(i, j)]

        return solve(0, 0)
