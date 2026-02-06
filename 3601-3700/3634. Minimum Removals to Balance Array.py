class Solution(object):
    def minRemoval(self, nums, k):
        nums.sort()
        n = len(nums)
        ans = n
        i = 0

        for j in range(n):
            while nums[j] > nums[i] * k:
                i += 1
            ans = min(ans, n - (j - i + 1))

        return ans
