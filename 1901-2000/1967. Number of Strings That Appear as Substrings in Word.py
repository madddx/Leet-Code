class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        c = 0
        for p in patterns:
            if p in word:
                c += 1
        return c
