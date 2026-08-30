class Solution:
    def minimumDeletions(self, nums):
        n = len(nums)

        minIndex = nums.index(min(nums))
        maxIndex = nums.index(max(nums))

        left = min(minIndex, maxIndex)
        right = max(minIndex, maxIndex)

        # Remove both from the front
        front = right + 1

        # Remove both from the back
        back = n - left

        # Remove one from each side
        frontBack = (left + 1) + (n - right)

        return min(front, back, frontBack)
