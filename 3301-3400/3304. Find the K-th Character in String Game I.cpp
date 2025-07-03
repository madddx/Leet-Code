class Solution {
public:
    int count_ones(int n) {
        int result = 0;
        while (n) {
            n &= n - 1;
            ++result;
        }
        return result;
    }

    char kthCharacter(int k) {
        return 'a' + count_ones(k - 1);
    }
};
