class Solution(object):
    def minimumDifference(self, nums, k):
        
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """ 
        nums = sorted(nums)[::-1]
        mini = float('inf')
        for i in range(0,len(nums)-k+1):
            v = nums[i] - nums[i+k-1]
            if v < mini:
                mini = v
        return mini

        
