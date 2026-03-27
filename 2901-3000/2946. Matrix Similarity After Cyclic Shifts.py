class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:
        n = len(mat[0])
        shift = k % n
        if shift == 0:
            return True
            
        for i, row in enumerate(mat):
            for j in range(n):
                if i % 2 == 0:
                    if row[j] != row[(j + shift) % n]:
                        return False
                else:
                    if row[j] != row[(j + n - shift) % n]:
                        return False
        return True
      
