class Solution:
    def rev(self, n: int) -> int:
        a = 0
        while(n > 0):
            a = a * 10 + (n % 10)
            n //= 10
        return a
    def mirrorDistance(self, n: int) -> int:
        m = self.rev(n)
        return abs(m - n)
