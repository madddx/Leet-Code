class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool foundValue = true;
        int new_value = original;
        while(foundValue) {
            for(vector<int>::const_iterator it = nums.cbegin(); it != nums.cend(); it++) {
                if(original == *it) {
                    new_value = (original << 1);
                    break;
                }
            }
            foundValue = (new_value != original);
            original = new_value;
        }
        return original;
    }
};
