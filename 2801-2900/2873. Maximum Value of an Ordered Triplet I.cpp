class Solution {
public:
    long long maximumTripletValue(vector<int>& v) {
        int n = v.size();
        if (n < 3) return 0; // At least 3 elements are needed

        long long maxA = v[0];      // Max v[i] so far
        long long maxA_B = LLONG_MIN; // Max (v[i] - v[j])
        long long maxA_B_C = 0;     // Max (v[i] - v[j]) * v[k]

        for (int j = 1; j < n - 1; j++) {
            maxA_B = max(maxA_B, maxA - v[j]); // Update max (v[i] - v[j])
            maxA = max(maxA, (long long)v[j]); // Update max v[i] seen so far
            maxA_B_C = max(maxA_B_C, maxA_B * (long long)v[j + 1]); // Compute (v[i] - v[j]) * v[k]
        }

        return maxA_B_C;
    }
};
