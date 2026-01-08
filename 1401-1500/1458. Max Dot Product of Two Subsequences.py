class Solution(object):
    def maxDotProduct(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        n1 = len(nums1)
        n2 = len(nums2)
  
        dp = [[-1000001] * n2 for _ in range(n1)]
        dp[n1-1][n2-1] = nums1[n1-1]*nums2[n2-1]
        for j in range(n2-2, -1, -1):
            dp[n1-1][j] = max(dp[n1-1][j+1], nums1[n1-1]*nums2[j])
        for i in range(n1-2, -1, -1):
            dp[i][n2-1] = max(dp[i+1][n2-1], nums1[i]*nums2[n2-1])
        
        for i in range(n1-2, -1, -1):
            for j in range(n2-2, -1, -1):
                dp[i][j] = max(dp[i+1][j], dp[i][j+1], dp[i+1][j+1], dp[i+1][j+1] + nums1[i]*nums2[j], nums1[i]*nums2[j])

        return dp[0][0]
