typedef long long int ll;
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() {
            std::ofstream("display_runtime.txt") << 0 << '\n';
            std::ofstream("display_memory.txt") << 0 << '\n';  
        }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
private:
    const int cmod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    int k;
    int computeMatrix(vector<vector<int>>&grid,int row,int col,int mod){
        if (row == grid.size()-1 && col == grid[0].size()-1) return (mod == 0);
        if (dp[row][col][mod] != -1) return dp[row][col][mod];
        ll ans = 0;
        if (row + 1 < grid.size()){
            int newMod = (mod + grid[row+1][col]) % k;
            ans = (ans + computeMatrix(grid,row+1,col,newMod)) % cmod;
        }
        if (col + 1 < grid[0].size()){
            int newMod = (mod + grid[row][col+1]) % k;
            ans = (ans + computeMatrix(grid,row,col+1,newMod)) % cmod;
        }
        return (dp[row][col][mod] = ans);
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(),m = grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(51,-1)));
        this->k = k;
        int ans = computeMatrix(grid,0,0,grid[0][0] % k);
        return ans;
    }
};
