class Solution:
    def uniformArray(self, a):
        mn = float('inf')
        oddCnt = 0
        for x in a:
            mn = min(mn, x)
            if x % 2 == 1:
                oddCnt += 1
        # min Element is ODD(remaining even > min) or All Even!
        return mn % 2 == 1 or oddCnt == 0
