class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr;
        for(int num : nums) {
            if(arr.empty() || num != arr.back()) arr.push_back(num);
        }
        int ans = 0;
        for(int i = 1, n = arr.size() - 1; i < n; i++) {
            if((arr[i - 1] < arr[i]) == (arr[i + 1] < arr[i])) {
                ans++;
            }
        }
        return ans;
    }
};
