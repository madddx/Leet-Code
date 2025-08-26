class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double max_diagonal = -1.0;   
        int max_area = -1;

        for (auto& rect : dimensions) {
            int l = rect[0], w = rect[1];
            double diagonal = sqrt(1.0 * l * l + 1.0 * w * w);
            int area = l * w;

            if (diagonal > max_diagonal) {
                max_diagonal = diagonal;
                max_area = area;
            } else if (diagonal == max_diagonal) {
                // diagonals equal  
                max_area = max(max_area, area);
            }
        }

        return max_area;
    }
};
