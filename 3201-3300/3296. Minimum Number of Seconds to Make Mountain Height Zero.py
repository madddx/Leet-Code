from typing import List

class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        workerTimes.sort()
        
        low_time = 0
        high_time = 10**16
        min_required_time = high_time
        
        # Outer Binary Search: Finding the minimum required time
        while low_time <= high_time:
            mid_time = low_time + (high_time - low_time) // 2
            total_height_reduced = 0
            
            for base_time in workerTimes:
                # Inner Binary Search: Finding max height THIS worker can reduce in 'mid_time'
                low_height = 0
                high_height = mountainHeight
                max_worker_height = 0
                
                while low_height <= high_height:
                    mid_height = low_height + (high_height - low_height) // 2
                    
                    # Formula for sum of first N natural numbers
                    time_needed = base_time * mid_height * (mid_height + 1) // 2
                    
                    if time_needed <= mid_time:
                        max_worker_height = mid_height
                        low_height = mid_height + 1
                    else:
                        high_height = mid_height - 1
                
                total_height_reduced += max_worker_height
                
                # Early Exit Optimization
                if total_height_reduced >= mountainHeight:
                    break
            
            # Adjust outer binary search bounds
            if total_height_reduced >= mountainHeight:
                min_required_time = mid_time
                high_time = mid_time - 1
            else:
                low_time = mid_time + 1
                
        return min_required_time
