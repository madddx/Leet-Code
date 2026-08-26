class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        l, ones, minlen = 0, 0, float('inf')
        ans = ""
        for r in range(len(s)):
            if s[r] == '1': ones += 1
            while ones == k:
                w = s[l:r+1]
                if len(w) < minlen or (len(w) == minlen and w < ans):
                    ans = w
                    minlen = len(w)
                if s[l] == '1': ones -= 1
                l += 1
        return ans
