class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& g) {
        int rows = g.size();
        int cols = g[0].size();
        int inf = rows+cols;

        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++) {
                if(g[r][c] == 1) g[r][c] = 0;
                else g[r][c] = 1;
            }
        }

        for(int r=0;r<rows;r++) {
            for(int c=0;c<cols;c++) {
                if(g[r][c] == 0)continue;
                int left = inf, top = inf;
                if(c-1 >=0) left = g[r][c-1];
                if(r-1 >=0) top = g[r-1][c];
                g[r][c] = min(left,top)+1;
            }
        }
        for(int r = rows-1; r>=0; r--) {
            for(int c= cols-1; c>=0; c--) {
                if(g[r][c] == 0)continue;
                int right = inf, bottom = inf;
                if(r+1 < rows) bottom = g[r+1][c];
                if(c+1 < cols) right = g[r][c+1];
                g[r][c] = min(g[r][c], min(right,bottom)+1);
            }
        }
        return g;
    }
};
