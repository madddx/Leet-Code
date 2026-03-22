class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        def rotate(matrix):
            n = len(matrix)
            for i in range(n):
                for j in range(i+1, n):
                    matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
            for row in matrix:
                row.reverse()
            return matrix
        for i in range(4):
            if rotate(mat) == target:
                return True
        return False
