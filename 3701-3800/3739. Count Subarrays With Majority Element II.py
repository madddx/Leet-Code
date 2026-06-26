class Solution:
    def countMajoritySubarrays(self, A: List[int], target: int) -> int:
        n = len(A)
        count = [1] + [0] * (n + n + 2)
        acc = [1] + [0] * (n + n + 2)
        res = pre = 0
        for a in A:
            pre += 1 if a == target else -1
            count[pre] += 1
            acc[pre] = acc[pre - 1] + count[pre]
            res += acc[pre - 1]
        return res
