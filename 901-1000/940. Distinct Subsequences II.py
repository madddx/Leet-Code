class Solution:
    def distinctSubseqII(self, s):
        n = len(s)
        MOD = 10**9 + 7

        dp = [1] * n
        countEndWith = [0] * 26

        total = 0

        for i in range(n):
            idx = ord(s[i]) - ord('a')

            dp[i] = (1 + total - countEndWith[idx] + MOD) % MOD

            total = (total + dp[i]) % MOD

            countEndWith[idx] = (countEndWith[idx] + dp[i]) % MOD

        return total
