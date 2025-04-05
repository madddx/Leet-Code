class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        // Step 1: Compute bitwise OR of all elements
        int or_all = 0;
        for (int num : nums) {
            or_all |= num;
        }

        // Step 2: Compute number of subsets that include each bit
        // 2^(n-1) subsets will include each bit
        int multiplier = 1 << (nums.size() - 1);

        // Step 3: Final result
        return or_all * multiplier;
    }
};
