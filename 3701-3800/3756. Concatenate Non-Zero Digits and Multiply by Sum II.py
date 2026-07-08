class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 10**9 + 7
        n = len(s)

        pow10 = [1] * (n + 1)
        for i in range(1, n + 1):
            pow10[i] = (pow10[i - 1] * 10) % MOD

        # idx[i] = number of non-zero digits before index i
        idx = [0] * (n + 1)

        # val[i] = number formed by first i non-zero digits
        val = [0] * (n + 1)

        # total[i] = sum of first i non-zero digits
        total = [0] * (n + 1)

        cnt = 0

        for i, ch in enumerate(s):
            digit = int(ch)

            if digit != 0:
                cnt += 1
                val[cnt] = (val[cnt - 1] * 10 + digit) % MOD
                total[cnt] = total[cnt - 1] + digit

            idx[i + 1] = cnt

        ans = []

        for l, r in queries:

            left = idx[l]
            right = idx[r + 1]

            # No non-zero digit in the range
            if left == right:
                ans.append(0)
                continue

            length = right - left

            number = (val[right] - val[left] * pow10[length]) % MOD
            sum_digits = total[right] - total[left]

            ans.append((number * sum_digits) % MOD)

        return ans
