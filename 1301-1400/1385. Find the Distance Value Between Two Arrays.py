class Solution:
    def findTheDistanceValue(self, arr1, arr2, d):
        c = 0
        for n in arr1:
            if self.isValid(n, arr2, d):
                c += 1
        return c

    def isValid(self, n, arr, d):
        for e in arr:
            if abs(e - n) <= d:
                return False
        return True
