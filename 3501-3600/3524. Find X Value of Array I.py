class Solution:
    def resultArray(self, nums, k):
        n = len(nums)
        nums = [x % k for x in nums]
        res = [0] * k

        for req in range(k):
            dp = {}

            def solve(i, prevProd):
                if i >= n:
                    return 0
                if (i, prevProd) in dp:
                    return dp[(i, prevProd)]

                skip = 0
                take = 0

                # Skip current element (only if no subarray started yet)
                if prevProd == k:
                    skip = solve(i + 1, k)

                # Take current element
                if prevProd == k:
                    curProd = nums[i]
                else:
                    curProd = (prevProd * nums[i]) % k

                take += 1 if curProd == req else 0
                take += solve(i + 1, curProd)

                dp[(i, prevProd)] = take + skip
                return dp[(i, prevProd)]

            res[req] = solve(0, k)

        return res
