class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int parent[26];
        for (int i = 0; i < 26; i++) parent[i] = i;
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        };
        for (int i = 0; i < s1.size(); i++) {
            int a = s1[i] - 'a', b = s2[i] - 'a';
            int ra = find(a), rb = find(b);
            if (ra != rb) parent[ max(ra, rb) ] = min(ra, rb);
        }
        for (char &c : baseStr) {
            c = char(find(c - 'a') + 'a');
        }
        return baseStr;
    }
};
