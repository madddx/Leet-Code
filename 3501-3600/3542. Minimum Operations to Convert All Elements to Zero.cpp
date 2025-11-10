using namespace std;

class Solution {
public:
    inline int minOperations(vector<int>& nums) {
        int ans = 0;
        static bool seen[100001];
        memset(seen, 0, sizeof(seen));

        static int monoStackArr[200000]; 
        int top = 0;

        for (int curr : nums) {
            if (curr == 0) {
                while (top) {
                    seen[monoStackArr[--top]] = false;
                }
                continue;
            }
            while (top && monoStackArr[top - 1] > curr) {
                seen[monoStackArr[--top]] = false;
            }
            if (!seen[curr]) {
                ++ans;
                seen[curr] = true;
            }
            monoStackArr[top++] = curr;
        }
        return ans;
    }
};

struct FastIOS {
    FastIOS() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;
