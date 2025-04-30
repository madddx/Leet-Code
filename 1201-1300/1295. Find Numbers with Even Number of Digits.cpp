#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int x : nums) {
            int digits = 0;
            while (x > 0) {
                digits++;
                x /= 10;
            }
            if ((digits & 1) == 0) 
                count++;
        }
        return count;
    }
};
