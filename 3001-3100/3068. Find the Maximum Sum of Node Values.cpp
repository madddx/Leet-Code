class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = 0;
        int n = 0;
        long long d = 1 << 30;
        for(auto &x : nums){
            long long y = x ^ k;
            res += max((long long)x, y);
            if(x < y){
                n = 1 - n;
            }
            // 1. 变的个数是奇数，有两种补救方法，要么再变一个， 要么少变一个。 再变一个就要减去因为多变而受到的损失
            // 少变一个就要减去不变而少得到的奖励。
            d = min(d, abs(x-y));
        }
        return res - n * d;
    }
};
