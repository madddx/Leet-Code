from sortedcontainers import SortedList

class Solution:
    def minimumCost(self, nums, k, dist):
        k -= 1
        current_sum = sum(nums[:dist + 2])
        left = SortedList(nums[1:dist + 2])
        right = SortedList()

        while len(left) > k:
            x = left.pop()
            current_sum -= x
            right.add(x)

        ans = current_sum

        for i in range(dist + 2, len(nums)):
            out = nums[i - dist - 1]
            if out in left:
                left.remove(out)
                current_sum -= out
            else:
                right.remove(out)

            inc = nums[i]
            if left and inc < left[-1]:
                left.add(inc)
                current_sum += inc
            else:
                right.add(inc)

            while len(left) < k:
                x = right.pop(0)
                left.add(x)
                current_sum += x
            while len(left) > k:
                x = left.pop()
                current_sum -= x
                right.add(x)

            ans = min(ans, current_sum)

        return ans
