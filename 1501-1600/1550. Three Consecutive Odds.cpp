class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        return arr.size()<3?0:any_of(arr.begin(), arr.end()-2, [&, i=-1](int x) mutable
        { return 1&x&arr[++i+1]&arr[i+2];});
    }
};
