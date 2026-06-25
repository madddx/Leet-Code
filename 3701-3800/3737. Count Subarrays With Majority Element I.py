class Solution:
    def countMajoritySubarrays(self, nums, target):
        n = len(nums)
        cnt = 0

        for i in range(n):
            freq = 0

            for j in range(i, n):
                if nums[j] == target:
                    freq += 1

                length = j - i + 1

                if freq > length // 2:
                    cnt += 1

        return cnt
