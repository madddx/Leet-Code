from typing import List

class Solution:
    def earliestFinishTime(
        self,
        landStartTime: List[int],
        landDuration: List[int],
        waterStartTime: List[int],
        waterDuration: List[int]
    ) -> int:
        n = len(landStartTime)
        m = len(waterStartTime)
        ans = float('inf')

        # Step 1: Find earliest finish time among all land tasks
        min_l = float('inf')
        for i in range(n):
            min_l = min(min_l, landStartTime[i] + landDuration[i])

        # Step 2: Find earliest finish time among all water tasks
        min_w = float('inf')
        for j in range(m):
            min_w = min(min_w, waterStartTime[j] + waterDuration[j])

        # Step 3: Best land task first, then each water task
        for j in range(m):
            ans = min(ans, max(waterStartTime[j], min_l) + waterDuration[j])

        # Step 4: Best water task first, then each land task
        for i in range(n):
            ans = min(ans, max(landStartTime[i], min_w) + landDuration[i])

        return ans
