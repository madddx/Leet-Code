class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        st = set(nums)

        mn = min(nums)
        mx = max(nums)

        ans = []

        for num in range(mn, mx + 1):
            if num not in st:
                ans.append(num)

        return ans
