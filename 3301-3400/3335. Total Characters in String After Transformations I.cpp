class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // a -> 26, ab
        // b -> 26, bc
        // ...
        // y -> 26, yz

        // z -> 1, ab
        // ab -> 24, yz
        // yz -> 1, zab
        // z -> 26, zab

        constexpr int MOD = 1e9 + 7;
        long cnts[26] = {};
        for (char c : s) ++cnts[c - 'a'];
        while (t >= 26) {
            long tmp[26] = {};
            for (int i = 0; i < 25; ++i) tmp[i + 1] += cnts[i];
            tmp[0] += cnts[25];
            tmp[1] += cnts[25];
            for (int i = 0; i < 26; ++i) {
                cnts[i] += tmp[i];
                cnts[i] %= MOD;
            }
            t -= 26;
        }

        long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += cnts[i];
            if (i + t >= 26) ans += cnts[i];
            ans %= MOD;
        }
        return ans % MOD;
    }
};
