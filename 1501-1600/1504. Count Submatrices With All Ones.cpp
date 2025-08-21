class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0)
                    height[j] = 0;
                else
                    height[j] += 1;
            }

            for (int j = 0; j < n; j++) {
                int min_h = height[j];
                for (int k = j; k >= 0 && min_h > 0; k--) {
                    min_h = min(min_h, height[k]);
                    ans += min_h;
                }
            }
        }

        return ans;
    }
};
