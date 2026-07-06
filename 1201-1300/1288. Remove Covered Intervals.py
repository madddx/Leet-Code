class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        
        remaining_count = 0
        max_right = 0
        
        for _, r in intervals:
            if r > max_right:
                remaining_count += 1
                max_right = r
                
        return remaining_count
