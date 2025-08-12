#include <vector>
using namespace std;

class Solution {
    static constexpr int MOD = 1e9 + 7;
    static constexpr int MAX_N = 300;
    static constexpr int MAX_X = 5;

    // Precomputed answers: precomputed[n][x]
    static vector<vector<int>> precomputed;

    // Static fast integer power
    static int ipow(int base, int exp) {
        int res = 1;
        while (exp--) res *= base;
        return res;
    }

    // Build the table once
    static vector<vector<int>> compute() {
        vector<vector<int>> ans(MAX_N + 1, vector<int>(MAX_X + 1, 0));

        for (int x = 1; x <= MAX_X; ++x) {
            // dp[s][k] = #ways to make sum = s using exactly k distinct x-th powers
            vector<vector<int>> dp(MAX_N + 1, vector<int>(MAX_N + 1, 0));
            dp[0][0] = 1;

            // For each possible i^x
            for (int i = 1; ; ++i) {
                int p = ipow(i, x);
                if (p > MAX_N) break;
                // 0/1-knapsack style: include this power
                for (int s = MAX_N; s >= p; --s) {
                    for (int k = 0; k < MAX_N; ++k) {
                        dp[s][k+1] = (dp[s][k+1] + dp[s - p][k]) % MOD;
                    }
                }
            }

            // Sum over all k to get total ways for each n
            for (int s = 0; s <= MAX_N; ++s) {
                long long total = 0;
                for (int k = 0; k <= MAX_N; ++k) {
                    total = (total + dp[s][k]) % MOD;
                }
                ans[s][x] = (int)total;
            }
        }

        return ans;
    }

public:
    int numberOfWays(int n, int x) {
        return precomputed[n][x];
    }
};

// Definition of the static member
vector<vector<int>> Solution::precomputed = Solution::compute();
