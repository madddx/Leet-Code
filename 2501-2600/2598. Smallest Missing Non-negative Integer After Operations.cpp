class Solution {
public:

    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> rems(value + 1, 0);
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0)
                ++rems[nums[i] % value];
            else
                ++rems[value + (nums[i] % value)];
        }
        rems[0] += rems[value];
        while(rems[ret % value]-- != 0)
            ++ret;
        return ret;
    }
};
