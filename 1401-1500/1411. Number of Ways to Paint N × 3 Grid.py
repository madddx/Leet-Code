class Solution:
    def numOfWays(self, n):
        MOD = 10**9 + 7
        aba = 6 
        abc = 6
        
        for i in range(2, n + 1):
            new_aba = (3 * aba + 2 * abc) % MOD
            new_abc = (2 * aba + 2 * abc) % MOD
            aba, abc = new_aba, new_abc
        
        #return (aba + abc) % MOD
