class Fenwick:
    def __init__(self, n):
        self.n = n
        self.bits = [0] * (n + 1)
    def update(self, index, value):
        index += 1
        while index <= self.n:
            self.bits[index] += value
            index += index & -index
    def query(self, index): 
        index += 1
        curans = 0
        while index:
            curans += self.bits[index]
            index -= index & -index
        return curans
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        n = len(nums)
        freq = {}
        for x in nums:
            freq[x] = freq.get(x, 0) + 1
        vals = sorted(freq)
        ranks = {val: i for i, val in enumerate(vals)}
        m = len(vals)
        ft = Fenwick(m)
        for k, val in freq.items():
            ft.update(ranks[k], val)
        ans = 0
        for j in range(1, m):
            gap = vals[j] - vals[j-1]
            above = n - ft.query(j-1)
            ans += gap * above
        return ans
