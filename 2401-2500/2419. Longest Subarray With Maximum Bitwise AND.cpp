class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int cons = 1, res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] && nums[i] == maxi) cons++;
            else cons = 1;
            res = max(res, cons);
        }
        return res;
    }
};
