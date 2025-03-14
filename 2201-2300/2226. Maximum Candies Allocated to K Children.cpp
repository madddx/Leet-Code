class Solution {
    bool isPossible(vector<int>& can, long long mid, long long k) {
        long long total = 0;
        for(auto x: can) {
            total += x / mid;
        }
        return total >= k;
    }
public:
    int maximumCandies(vector<int>& can, long long k) {
        long long n = can.size(), end = 0, start = 1;
        for(auto x: can) end += x;
        end /= k;
        while(start <= end) {
            long long mid = start + (end - start) / 2;
            if(isPossible(can, mid, k)) start = mid + 1;
            else end = mid - 1;
        }
        return end;
    }
};
