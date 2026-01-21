class Solution(object):
    def minBitwiseArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = []
        for num in nums:
            if num == 2:
                res.append(-1)
            else:
                # num +1 = ...1000 
                # num = ...0111
                a = num - ((num+1) & num)    # a = 0111
                res.append(num - a//2 - 1)
        return res

        
