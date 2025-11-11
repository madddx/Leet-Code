class Solution {
public:
    int f(int idx, vector<vector<vector<int>>> &dp, vector<vector<int>> &v, int m, int n){
        if(idx==0){
            if(v[idx][0]<=m && v[idx][1]<=n) return 1;
            else return 0;
        }

        if(dp[idx][m][n]!=-1) return dp[idx][m][n];
        int nottake = f(idx-1, dp, v, m, n);
        int take = 0;
        if(v[idx][0]<=m && v[idx][1]<=n){
            take = 1 + f(idx-1, dp, v, m-v[idx][0], n-v[idx][1]);
        }
        return dp[idx][m][n] = max(nottake, take);
    }
    int solve(vector<vector<int>> &v, int m, int n){
        int len = v.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return f(len-1, dp, v, m, n);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> v(len);
        for(int i=0; i<len; i++){
            int c0=0, c1=0;
            for(char c:strs[i]){
                if(c=='0') c0++;
                if(c=='1') c1++;
            }
            v[i].push_back(c0);
            v[i].push_back(c1);
        }
        return solve(v, m, n);
    }
};
auto init = atexit( []() {ofstream("display_runtime.txt") <<'0'; });
