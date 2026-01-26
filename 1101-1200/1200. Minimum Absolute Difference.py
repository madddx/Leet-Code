class Solution(object):
    def minimumAbsDifference(self, arr):
        """
        :type arr: List[int]
        :rtype: List[List[int]]
        """
        # 1. Sort the array
        arr.sort()
        
        # 2. These must be indented to stay inside the function!
        min_diff = float('inf')
        result = []
        
        for i in range(len(arr) - 1):
            diff = arr[i+1] - arr[i]
            
            if diff < min_diff:
                # Found a NEW smaller gap
                min_diff = diff
                result = [[arr[i], arr[i+1]]]
            elif diff == min_diff:
                # Found another pair with the same gap
                result.append([arr[i], arr[i+1]])
                
        return result
