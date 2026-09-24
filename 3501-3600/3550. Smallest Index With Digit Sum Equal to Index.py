class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i, n in enumerate(nums):
            total = sum(int(c) for c in str(n))
            if total == i:
                return i
        return -1
