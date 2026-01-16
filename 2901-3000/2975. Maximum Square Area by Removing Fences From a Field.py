class Solution(object):
    def maximizeSquareArea(self, m, n, hFences, vFences):
        """
        :type m: int
        :type n: int
        :type hFences: List[int]
        :type vFences: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        hFences = hFences + [1, m]
        vFences = vFences + [1, n]
        hFences.sort()
        vFences.sort()
        
        h_gaps = set()
        for i in range(len(hFences)):
            for j in range(i + 1, len(hFences)):
                h_gaps.add(hFences[j] - hFences[i])
                
        max_side = -1
        for i in range(len(vFences)):
            for j in range(i + 1, len(vFences)):
                gap = vFences[j] - vFences[i]
                if gap in h_gaps:
                    if gap > max_side:
                        max_side = gap
                        
        if max_side == -1:
            return -1
            
        return (max_side * max_side) % MOD
