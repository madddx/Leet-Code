class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> v(nums.size());
        int prev = 0;

        for (int i = 0; i < nums.size(); i++) {
            prev = (prev * 2 + nums[i]) % 5;
            v[i] = (prev == 0);
        }
        return v;
    }
};
