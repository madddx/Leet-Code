class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        return list(range((s:=sum(x<target for x in nums)), s+nums.count(target)))      
