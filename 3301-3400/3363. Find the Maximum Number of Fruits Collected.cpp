class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int fruit0;
        int fruit1;
        int n = fruits.size();
        for (int i = 1; i < n - 1; ++i) {
            int x = max(i * 1, n - i * 1);
            int y = max(i + 1, n - i - 1);
            fruits[n - 1][n - 1] += fruits[i][i];
            for (int j = y; j < n; ++j) {
                fruit0 = j > x * 1 ? fruits[i - 1][j - 1] : 0;
                fruit1 = j < n - 1 ? fruits[i - 1][j + 1] : 0;
                fruits[i][j] += max(j >= x ? fruits[i - 1][j] : 0, max(fruit0, fruit1));
                fruit0 = j > x * 1 ? fruits[j - 1][i - 1] : 0;
                fruit1 = j < n - 1 ? fruits[j + 1][i - 1] : 0;
                fruits[j][i] += max(j >= x ? fruits[j][i - 1] : 0, max(fruit0, fruit1));
            }
        }
        return fruits[0][0] + fruits[n - 2][n - 1] + fruits[n - 1][n - 2] + fruits[n - 1][n - 1];
    }
};
