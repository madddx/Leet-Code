class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        steps = [1 for i in range(len(arr))]
        stack = []
        n = len(arr)
        for i in range(n + 1):
            while len(stack) > 0 and (i == n or arr[stack[-1]] < arr[i]):
                pop_indices = [stack.pop()]
                while stack and arr[stack[-1]] == arr[pop_indices[0]]:
                    pop_indices.append(stack.pop())
                for j in pop_indices:
                    if i < n and i - j <= d:
                        steps[i] = max(steps[i], steps[j] + 1)
                    if len(stack) > 0 and j - stack[-1] <= d:
                        steps[stack[-1]] = max(steps[stack[-1]], steps[j] + 1)
            if i < n:
                stack.append(i)
        return max(steps)
