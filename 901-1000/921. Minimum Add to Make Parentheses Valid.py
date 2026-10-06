class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open_count = 0
        insertions = 0

        for c in s:
            if c == '(':
                open_count += 1
            elif open_count > 0:
                open_count -= 1
            else:
                insertions += 1

        return insertions + open_count
