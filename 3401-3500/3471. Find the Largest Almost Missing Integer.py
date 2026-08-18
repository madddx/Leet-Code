from typing import List

class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)

        freq = [0] * 51

        for x in nums:
            freq[x] += 1

        if k == 1:
            for x in range(50, -1, -1):
                if freq[x] == 1:
                    return x

            return -1

        if k == n:
            return max(nums)

        answer = -1

        if freq[nums[0]] == 1:
            answer = max(answer, nums[0])

        if freq[nums[-1]] == 1:
            answer = max(answer, nums[-1])

        return answer
