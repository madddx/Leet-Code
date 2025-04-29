#include <vector>
using namespace std;

class Solution {
public:
    /**
     * Count of subarrays where the global maximum appears at least k times.
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    long long countSubarrays(vector<int>& a, int k) {
        int n = a.size();
        if (n < k) return 0;

        // Find global max
        int M = a[0];
        for (int v : a) if (v > M) M = v;

        long long total = 1LL * n * (n + 1) / 2;
        long long bad = 0;
        int left = 0, cnt = 0;

        // Sliding window to count subarrays with fewer than k occurrences of M
        for (int right = 0; right < n; ++right) {
            if (a[right] == M) ++cnt;
            while (cnt >= k) {
                if (a[left] == M) --cnt;
                ++left;
            }
            bad += (right - left + 1);
        }

        return total - bad;
    }
};
