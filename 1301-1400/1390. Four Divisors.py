class Solution:
    def sumFourDivisors(self, nums):
        total = 0
        for n in nums:
            count = 0
            sum = 0
            root = int(n ** 0.5)
            for i in range(1, root + 1):
                if n % i == 0:
                    j = n // i
                    if i == j:
                        count += 1
                        sum += i
                    else:
                        count += 2
                        sum += i + j
                    if count > 4:
                        break
            if count == 4:
                total += sum
        return total
