class Solution(object):
    def largestMagicSquare(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        R, C = len(grid), len(grid[0])
        
        # 1. Prefix Sums (Standard)
        # Using simple lists for speed
        row_p = [[0] * (C + 1) for _ in range(R)]
        col_p = [[0] * C for _ in range(R + 1)]
        d1_p = [[0] * (C + 1) for _ in range(R + 1)]
        d2_p = [[0] * (C + 2) for _ in range(R + 1)]

        for r in range(R):
            row_r = row_p[r]
            d1_r = d1_p[r]
            d2_r = d2_p[r]
            # Next row references
            col_next = col_p[r+1]
            col_curr = col_p[r]
            d1_next = d1_p[r+1]
            d2_next = d2_p[r+1]
            
            g_r = grid[r] # Local access is faster
            
            for c in range(C):
                val = g_r[c]
                row_r[c+1] = row_r[c] + val
                col_next[c] = col_curr[c] + val
                d1_next[c+1] = d1_r[c] + val
                d2_next[c] = d2_r[c+1] + val

        # 2. Search
        # We assume result is at least 1
        for k in range(min(R, C), 1, -1):
            
            # Optimization: Pre-calculate bounds
            r_limit = R - k + 1
            c_limit = C - k + 1
            
            for r in range(r_limit):
                for c in range(c_limit):
                    
                    # A. Check Diagonals (O(1))
                    diag1 = d1_p[r+k][c+k] - d1_p[r][c]
                    diag2 = d2_p[r+k][c] - d2_p[r][c+k]
                    
                    if diag1 != diag2:
                        continue
                        
                    target = diag1
                    
                    # B. Aggressive Pruning: Check Borders (O(1))
                    # Top Row
                    if (row_p[r][c+k] - row_p[r][c]) != target: continue
                    # Bottom Row
                    if (row_p[r+k-1][c+k] - row_p[r+k-1][c]) != target: continue
                    # Left Col
                    if (col_p[r+k][c] - col_p[r][c]) != target: continue
                    # Right Col
                    if (col_p[r+k][c+k-1] - col_p[r][c+k-1]) != target: continue

                    # C. Check Remaining Inner Rows/Cols
                    # Only loop if borders match. Loop range is reduced (1 to k-2)
                    match = True
                    for i in range(1, k - 1):
                        # Inner Row
                        if (row_p[r+i][c+k] - row_p[r+i][c]) != target:
                            match = False
                            break
                        # Inner Col
                        if (col_p[r+k][c+i] - col_p[r][c+i]) != target:
                            match = False
                            break
                    
                    if match:
                        return k
                        
        return 1
