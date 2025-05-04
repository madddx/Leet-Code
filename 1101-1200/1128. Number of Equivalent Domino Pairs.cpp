class Solution {
public:
    int numEquivDominoPairs(std::vector<std::vector<int>>& dominoes) {
        std::unordered_map<int, int> ctr;
        int ans = 0;

        for (const auto& domino : dominoes) {
            int x = domino[0];
            int y = domino[1];
            ctr[1 << x | 1 << y]++;}

        for (const auto& count : ctr) {
            ans += count.second * (count.second - 1);}

        return ans / 2;}
