class Solution:
    def concatenatedBinary(self, n: int) -> int:
        MOD = 1_000_000_007
        result = 0

        for i in range(1, n + 1):
            # Shift result to make space for i's binary digits
            result = ((result << i.bit_length()) + i) % MOD

        return result
