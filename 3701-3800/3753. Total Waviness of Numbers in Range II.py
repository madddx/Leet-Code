class Solution:

    def solve(self, n: int) -> int:

        if n <= 0:
            return 0

        s = str(n)
        memo = {}

        def dfs(pos, tight, started, prev2, prev1):

            if pos == len(s):
                return (0, 1)  # (waviness, count)

            key = (pos, tight, started, prev2, prev1)

            if key in memo:
                return memo[key]

            total_waviness = 0
            total_cnt = 0

            limit = int(s[pos]) if tight else 9

            for d in range(limit + 1):

                next_tight = tight and (d == limit)

                if not started and d == 0:

                    child_waviness, child_cnt = dfs(pos + 1,next_tight,False,10,10)

                    total_waviness += child_waviness
                    total_cnt += child_cnt

                else:

                    add = 0

                    if not started:

                        n_prev2 = 10
                        n_prev1 = d

                    else:

                        if prev2 != 10:

                            peak = (prev1 > prev2 and prev1 > d)
                            valley = (prev1 < prev2 and prev1 < d)

                            if peak or valley:
                                add = 1

                        n_prev2 = prev1
                        n_prev1 = d

                    child_waviness, child_cnt = dfs(pos + 1,next_tight,True,n_prev2,n_prev1)

                    total_waviness += (child_waviness +add * child_cnt)
                    total_cnt += child_cnt

            memo[key] = (total_waviness, total_cnt)
            return memo[key]

        return dfs(0, True, False, 10, 10)[0]

    def totalWaviness(self, num1: int, num2: int) -> int:
        return self.solve(num2) - self.solve(num1 - 1)
