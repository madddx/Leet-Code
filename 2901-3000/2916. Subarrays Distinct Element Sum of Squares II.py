class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)
        s = [0] * (4 * n)
        q = [0] * (4 * n)
        lz = [0] * (4 * n)

        def app(o, ln, k):
            q[o] += 2 * k * s[o] + k * k * ln
            s[o] += k * ln
            lz[o] += k

        def upd(o, l, r, L, R):
            if L <= l and r <= R:
                app(o, r - l + 1, 1)
                return
            m = (l + r) >> 1
            if lz[o]:
                app(2*o, m - l + 1, lz[o])
                app(2*o+1, r - m, lz[o])
                lz[o] = 0
            if L <= m:
                upd(2*o, l, m, L, R)
            if R > m:
                upd(2*o+1, m+1, r, L, R)
            s[o] = s[2*o] + s[2*o+1]
            q[o] = q[2*o] + q[2*o+1]

        last = {}
        ans = 0
        for i, x in enumerate(nums):
            upd(1, 0, n-1, last.get(x, -1) + 1, i)
            last[x] = i
            ans = (ans + q[1]) % MOD
        return ans
