class Solution:
    def minBitwiseArray(self, nums):
        ans = []

        for num in nums:
            
            if num == 2:
                ans.append(-1)
                continue

            mask = 1
            while num & mask:
                mask <<= 1
            leading_one = mask >> 1   # step back to the last 1-bit

            ans.append(num - leading_one)

        return ans
