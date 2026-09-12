from typing import List


class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        K = 4

        intervals = [
            [l, r, w, i]
            for i, (l, r, w) in enumerate(intervals)
        ]

        intervals.sort(key=lambda x: x[1])

        ends = [x[1] for x in intervals]

        dp = [[None] * (n + 1) for _ in range(K + 1)]

        for i in range(n + 1):
            dp[0][i] = (0, [])

        def better(a, b):
            if a is None:
                return False
            if b is None:
                return True

            if a[0] != b[0]:
                return a[0] > b[0]

            return a[1] < b[1]

        def lower_bound(length, target):
            lo = 0
            hi = length

            while lo < hi:
                mid = lo + (hi - lo) // 2

                if ends[mid] >= target:
                    hi = mid
                else:
                    lo = mid + 1

            return lo

        for i in range(1, n + 1):
            l, _, w, original_index = intervals[i - 1]

            p = lower_bound(i - 1, l)

            for k in range(1, K + 1):
                dp[k][i] = dp[k][i - 1]

                prev = dp[k - 1][p]

                if prev is not None:
                    ids = prev[1] + [original_index]

                    ids.sort()

                    take = (prev[0] + w, ids)

                    if better(take, dp[k][i]):
                        dp[k][i] = take

        answer = None

        for k in range(1, K + 1):
            if better(dp[k][n], answer):
                answer = dp[k][n]

        return answer[1]
