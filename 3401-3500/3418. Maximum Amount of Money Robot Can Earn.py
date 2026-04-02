class Solution:
    def maximumAmount(self, coins):
        m,n=len(coins),len(coins[0])
        NEG=float('-inf')
        dp=[[NEG]*3 for _ in range(n)]

        for k in range(3):
            dp[0][k]=max(coins[0][0],0) if k>0 else coins[0][0]

        for j in range(1,n):
            for k in range(2,-1,-1):
                dp[j][k]=max(dp[j][k], dp[j-1][k]+coins[0][j])
                if k>0:
                    dp[j][k]=max(dp[j][k], dp[j-1][k-1])

        for i in range(1,m):
            ndp=[[NEG]*3 for _ in range(n)]
            for j in range(n):
                for k in range(2,-1,-1):
                    if dp[j][k]!=NEG:
                        ndp[j][k]=max(ndp[j][k], dp[j][k]+coins[i][j])
                    if k>0 and dp[j][k-1]!=NEG:
                        ndp[j][k]=max(ndp[j][k], dp[j][k-1])
                    if j>0:
                        if ndp[j-1][k]!=NEG:
                            ndp[j][k]=max(ndp[j][k], ndp[j-1][k]+coins[i][j])
                        if k>0 and ndp[j-1][k-1]!=NEG:
                            ndp[j][k]=max(ndp[j][k], ndp[j-1][k-1])
            dp=ndp

        return dp[n-1][2]
