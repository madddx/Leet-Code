class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return 0;
        int cur = grid[i][j];
        grid[i][j]=0;
        cur+=dfs(i+1, j, grid);
        cur+=dfs(i-1, j, grid);
        cur+=dfs(i, j+1, grid);
        cur+=dfs(i, j-1, grid);
        return cur;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0){
                    ans = max(ans, dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};
