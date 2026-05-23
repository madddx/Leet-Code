class Solution:
    def check(self, nums: list[int]) -> bool:
        breaks = 0
        n = len(nums)

        for i in range(n):
            if nums[i] > nums[(i + 1) % n]:
                breaks += 1

        return breaks <= 1
