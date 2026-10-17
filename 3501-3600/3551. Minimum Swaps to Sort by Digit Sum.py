class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        digit_sum = lambda x: sum(map(int, str(x)))
        rank = {x: k for k, x in enumerate(sorted(nums, key=lambda x: (digit_sum(x), x)))}  # final position of each value
        home = [rank[x] for x in nums]  # where the value at each position must go

        swaps = 0
        for i in range(len(home)):
            while home[i] != i:  # send the value at i home, take that spot's value in exchange
                j = home[i]
                home[i], home[j] = home[j], home[i]
                swaps += 1

        return swaps
