class Solution {
private:
    void rec(int i, int prev, vector<string>& words, vector<int>& groups, vector<string>& ans) {
        if (i == words.size()) return;
        if (prev != groups[i]) ans.push_back(words[i]);
        rec(i + 1, groups[i], words, groups, ans);
    }

public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        rec(0, -1, words, groups, ans);
        return ans;
    }
};
