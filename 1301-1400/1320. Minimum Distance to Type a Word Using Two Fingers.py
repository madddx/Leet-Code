from functools import lru_cache

class Solution:
    def minimumDistance(self, word: str) -> int:

        @lru_cache(maxsize=None)
        def get_minimumDistance(idx, f1, f2):            
            if idx == len(word):
                return 0                
            c = word[idx]
            d1 = get_dist(f1, c) + get_minimumDistance(idx + 1, c, f2)
            d2 = get_dist(f2, c) + get_minimumDistance(idx + 1, f1, c)
            return min(d1, d2)
        
        def get_coordinate(c):
            if c == "Y": return (4, 0)
            elif c == "Z": return (4, 1)
            if   ord("A") <= ord(c) <= ord("F"): row, col = 0, ord(c) - ord("A")
            elif ord("G") <= ord(c) <= ord("L"): row, col = 1, ord(c) - ord("G")
            elif ord("M") <= ord(c) <= ord("R"): row, col = 2, ord(c) - ord("M")
            elif ord("S") <= ord(c) <= ord("X"): row, col = 3, ord(c) - ord("S")
            return (row, col)
            
        def get_dist(a, b):
            if a is None: return 0      # free initial placement
            A, B = get_coordinate(a), get_coordinate(b)
            return abs(A[0] - B[0]) + abs(A[1] - B[1])

        # One finger types word[0] for free, the other hasn't been placed yet (None)
        return get_minimumDistance(1, word[0], None)
