#Mp
class Solution:
    def minimumCost(self, nums):
        first = nums[0]
        rest = sorted(nums[1:])
        return first + rest[0] + rest[1]
