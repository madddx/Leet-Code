class Solution(object):
    def maxMatrixSum(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        count = 0
        min_neg = 9999999
        sum_all = 0
        for i in matrix:
            abs_now = [abs(j) for j in i]
            count += sum([1 for j in i if j <= 0])
            sum_all += sum(abs_now)
            if min_neg > min(abs_now):
                min_neg = min(abs_now)
            
        if count % 2 == 0:
            return sum_all
        else:
            return sum_all - 2*min_neg
