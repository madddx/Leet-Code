class Solution:
    def minimumCost(self, a: List[int]) -> int:
        return sum(a)-sum(sorted(a)[-3::-3])
