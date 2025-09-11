class Solution {
public:
    string sortVowels(string s) {
        vector<int> freq(128, 0);
        vector<bool> isVowel(128, false);
        string vowelList = "aeiouAEIOU";
        for (char v : vowelList) isVowel[v] = true;
        for (char c : s) {
            if (isVowel[c]) freq[c]++;
        }
        string sortedVowels = "AEIOUaeiou";
        int idx = 0;
        for (char &c : s) {
            if (isVowel[c]) {
          while (idx < sortedVowels.size() && freq[sortedVowels[idx]] == 0)
                {
                    idx++;
                }
                c = sortedVowels[idx];
                freq[sortedVowels[idx]]--;
            }
        }
        return s;
    }
};
