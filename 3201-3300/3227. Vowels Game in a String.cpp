class Solution {
public:
    static bool doesAliceWin(string& s) {
        return any_of(s.begin(), s.end(), [](char c) { return ((0x208222>>(c & 0x1f)) & 1); })?1:0;
    }
};
