class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for (const int num: nums)
            cnt += num % 3 ? 1 : 0;
        return cnt;
    }
};
