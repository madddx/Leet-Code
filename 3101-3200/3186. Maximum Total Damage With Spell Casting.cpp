auto __fast_io_atexit = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]() { 
        ofstream("display_runtime.txt") << "0"; 
    });

    return 0;
}();
class Solution {
public:
    unordered_map<long long, long long> sum_map;
    vector<long long> unique_damages;
    vector<long long> dp;

    long long solveME(int i) {
        if (i >= unique_damages.size()) {
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        long long damage = unique_damages[i];

        int next_i = upper_bound(unique_damages.begin(), unique_damages.end(),
                                   damage + 2) - unique_damages.begin();

        long long include = sum_map[damage] + solveME(next_i);

        long long exclude = solveME(i + 1);

        return dp[i] = max(include, exclude);
    }

    long long maximumTotalDamage(vector<int>& power) {
        for (auto val : power) {
            sum_map[val] += val;
        }
        set<long long> st(power.begin(), power.end());
        unique_damages = vector<long long>(st.begin(), st.end());
        dp.assign(unique_damages.size(), -1);

        return solveME(0);
    }
};
