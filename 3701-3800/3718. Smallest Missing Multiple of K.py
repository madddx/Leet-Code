class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        hasQ, qMax=0, 0
        for x in nums:
            q, r=divmod(x, k)
            if r==0:
                hasQ|=(1<<q)
                qMax=max(q, qMax)
        for q in range(1, qMax+1):
            if (hasQ>>q)&1==0:
                return q*k
        return (qMax+1)*k
