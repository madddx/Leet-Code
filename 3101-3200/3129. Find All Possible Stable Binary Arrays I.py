class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        
        MOD = 10**9 + 7
        
        @cache
        def dp(r_z, r_o, p):
            if r_z == 0 and r_o == 0:
                return 1
            else:
                answer = 0
                
                for i in range(1, limit+1):
                    if (p == 0 or p == -1) and r_o - i >= 0:
                        answer += dp(r_z, r_o - i, 1)
                    if (p == 1 or p == -1) and r_z - i >= 0:
                        answer += dp(r_z - i, r_o, 0)
                
                return answer
            
        return dp(zero, one, -1) % MOD
