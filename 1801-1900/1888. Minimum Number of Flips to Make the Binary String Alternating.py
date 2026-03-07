class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        t = s + s

        diff1 = 0
        diff2 = 0
        ans = float('inf')

        for i in range(2 * n):
            expect1 = '0' if i % 2 == 0 else '1'   # 0101...
            expect2 = '1' if i % 2 == 0 else '0'   # 1010...

            if t[i] != expect1:
                diff1 += 1
            if t[i] != expect2:
                diff2 += 1

            if i >= n:
                old_expect1 = '0' if (i - n) % 2 == 0 else '1'
                old_expect2 = '1' if (i - n) % 2 == 0 else '0'

                if t[i - n] != old_expect1:
                    diff1 -= 1
                if t[i - n] != old_expect2:
                    diff2 -= 1

            if i >= n - 1:
                ans = min(ans, diff1, diff2)

        return ans
      
