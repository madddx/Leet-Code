class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        auto const n = nums.size();
        auto increasing_max = 0;
        auto decreasing_max = 0;
        auto running_length = 1;

        auto llas = INT_MAX;
        for (int hi = 0; hi < nums.size(); ++hi) {
            if (nums[hi] <= llas) {
                running_length = 1;
            }
            llas = nums[hi];
            increasing_max = max(running_length++, increasing_max);
        }

        running_length = 1;
        auto last_seen = INT_MIN;

        for (int hi = 0; hi < nums.size(); ++hi) {
            if (nums[hi] >= last_seen) {
                running_length = 1;
            }
            last_seen = nums[hi];
            decreasing_max = max(running_length++, decreasing_max);
        } 

        return max(increasing_max, decreasing_max);
    }
};
