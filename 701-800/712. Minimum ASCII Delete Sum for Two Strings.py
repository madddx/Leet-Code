class Solution(object):
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        s1 = "#" + s1
        s2 = "#" + s2
        dp = [[0] * len(s2) for _ in range(len(s1))]

        for i in range(1, len(s1)):
            for j in range(1, len(s2)):
                if s1[i] == s2[j]:
                    dp[i][j] = dp[i - 1][j - 1] + ord(s1[i])  # 与LCS区别
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])

        # 回溯, 与题1092比较
        i, j = len(s1) - 1, len(s2) - 1
        res = 0
        while i >= 1 and j >= 1:
            if s1[i] == s2[j]:
                i -= 1
                j -= 1
            elif dp[i][j] == dp[i][j - 1]:
                res += ord(s2[j])
                j -= 1
            else:
                res += ord(s1[i])
                i -= 1

        while i >= 1:
            res += ord(s1[i])
            i -= 1
        while j >= 1:
            res += ord(s2[j])
            j -= 1

        return res
