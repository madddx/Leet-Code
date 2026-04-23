from collections import defaultdict

class Solution:
    def distance(self, nums):
        mp = defaultdict(list)

        for i, val in enumerate(nums):
            mp[val].append(i)

        ans = [0] * len(nums)

        for idx in mp.values():
            k = len(idx)

            prefix = [0] * k
            prefix[0] = idx[0]

            for i in range(1, k):
                prefix[i] = prefix[i - 1] + idx[i]

            for i in range(k):
                left = i * idx[i] - (prefix[i - 1] if i > 0 else 0)
                right = (prefix[k - 1] - prefix[i]) - (k - i - 1) * idx[i]

                ans[idx[i]] = left + right

        return ans
