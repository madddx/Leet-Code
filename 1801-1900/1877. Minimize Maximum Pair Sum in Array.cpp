class Solution(object):
    def minPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        nums = sorted(nums)
        p1 = 0
        p2 = len(nums)-1
        if len(nums) == 0:
            return 0
        while p1<p2:
            ans = max(ans, nums[p1]+nums[p2])
            p1 +=1
            p2 -=1
        return ans
        
