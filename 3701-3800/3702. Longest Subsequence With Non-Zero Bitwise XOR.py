from typing import List

class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        xor_value = 0
        has_non_zero = False

        for x in nums:
            xor_value ^= x

            if x != 0:
                has_non_zero = True

        if xor_value != 0:
            return len(nums)

        if has_non_zero:
            return len(nums) - 1

        return 0
