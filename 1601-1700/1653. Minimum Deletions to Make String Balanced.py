class Solution(object):
    def minimumDeletions(self, s):
        ans = 0
        b = 0
        for i in s:
            if i == 'b':
                b += 1
            elif b > 0:
                ans += 1
                b -= 1
        return ans
