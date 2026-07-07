class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x = 0
        total = 0
        place = 1

        while n > 0:
            d = n % 10

            if d != 0:
                x = d * place + x
                place *= 10
                total += d

            n //= 10

        return x * total
