from math import gcd, lcm

class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)
        LIMIT = 25200
        ans = 1

        for i in range(n):
            for j in range(i, n):
                prod, g, l = 1, 0, 1
                ok = True

                for k in range(i, j + 1):
                    prod *= nums[k]
                    if prod > LIMIT:
                        ok = False
                        break
                    g = gcd(g, nums[k])
                    l = lcm(l, nums[k])

                if ok and prod == g * l:
                    ans = max(ans, j - i + 1)

        return ans
