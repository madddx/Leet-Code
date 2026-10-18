class Solution:   
    def numOfWays(self, nums: List[int]) -> int:
        Mod=10**9+7
        import math
        def Subproblem(nums: List[int]):
            n=len(nums)
            if n<=2: return 1
            root=nums[0]
            left=[]
            right=[]
            for y in nums[1:]:
                if y<root: left.append(y)
                else: right.append(y)
            return Subproblem(right)*Subproblem(left)%Mod*math.comb(len(nums)-1, len(left))%Mod
        return int((Subproblem(nums)-1)%Mod)
