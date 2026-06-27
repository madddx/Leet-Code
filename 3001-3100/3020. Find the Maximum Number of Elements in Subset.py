class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        cnt = Counter(nums)
        ans = 1

        if 1 in cnt:
            ans = max(ans, cnt[1] if cnt[1] & 1 else cnt[1] - 1)

        for x in cnt:
            if x == 1:
                continue

            cur = x
            length = 0

            while True:
                if cur not in cnt:
                    length -= 1
                    break

                if cnt[cur] == 1:
                    length += 1
                    break

                # cnt[cur] >= 2
                length += 2

                # Prevent overflow / unnecessary squaring
                if cur * cur > 10**9:
                    length -= 1
                    break

                cur *= cur

            ans = max(ans, length)

        return ans
