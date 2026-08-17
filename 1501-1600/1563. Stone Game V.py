class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        ps = [0] + list(accumulate(stoneValue))
        @cache
        def dp(l: int, r: int) -> int:
            if l == r: return 0
            res = 0
            for i in range(l + 1, r + 1):
                left_sum, right_sum = ps[i] - ps[l], ps[r + 1] - ps[i]
                if left_sum > right_sum: res = max(res, dp(i, r) + right_sum)
                elif left_sum < right_sum: res = max(res, dp(l, i - 1) + left_sum)
                else: res = max(res, dp(l, i - 1) + left_sum, dp(i, r) + right_sum)
            return res
        
        return dp(0, len(stoneValue) - 1)
