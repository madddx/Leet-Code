class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        map<int,vector<int>>mpp;
        int n = grid.size();

        for(int i = 0; i < n ;i++){
            for(int j = 0 ;j < n;j++){
                mpp[i-j].push_back(grid[i][j]);
            }
        }

        for(auto &it : mpp){
            if(it.first < 0){
                sort(begin(it.second),end(it.second));
            }
            else{
                sort(begin(it.second),end(it.second),greater<int>());
            }
        }

        for(int i = n-1;i >=0;i--){
            for(int j = n-1;j >=0 ;j--){
                grid[i][j] = mpp[i-j].back();
                mpp[i-j].pop_back();
            }
        }

        return grid;
    }
};
