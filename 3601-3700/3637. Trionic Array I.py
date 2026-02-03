class Solution(object):
    def isTrionic(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        if n < 4 or nums[1] <= nums[0]:
            return False

        changes, direction = 0, 1

        for i in range(2, n):
            if nums[i] == nums[i - 1]:
                return False
            curr = 1 if nums[i] > nums[i - 1] else -1
            if curr != direction:
                changes += 1
                direction = curr
                if changes > 2:
                    return False

        return changes == 2 and direction == 1
