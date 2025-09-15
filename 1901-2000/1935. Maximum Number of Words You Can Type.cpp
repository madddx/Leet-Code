class Solution {
public:
    int canBeTypedWords(string text, string broken) {
        int mask = 0;
        for (int i = 0; i < broken.size(); i++) {
            mask |= 1 << (broken[i] - 97);
        }

        int count = 0;
        bool brokenWord = false;
        for (int i = 0; i <= text.size(); i++) {
            if (i < text.size() && text[i] >= 'a' && text[i] <= 'z' &&
                (mask & (1 << (text[i] - 97))) != 0)
            {
                brokenWord = true;
            }
            if (i == text.size() || text[i] == ' ') {
                if (!brokenWord) count++;
                brokenWord = false;
            }
        }
        return count;
    }
};
