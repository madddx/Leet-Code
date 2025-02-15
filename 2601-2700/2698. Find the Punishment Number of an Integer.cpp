bool valid(int root, int p) {
    string s = to_string(p);
    auto go = [&](this auto&& go, int i, int sum, int curr) -> bool {
        if(i >= s.size()) {
            return sum == root;
        }
        int x = s[i] - '0';
        return go(i + 1, sum - curr + 10*curr + x, 10*curr + x) || go(i + 1, sum + x, x);
    };
    return go(0, 0, 0);
}

int punishment[1001];
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= 1000; i++) {
        if(valid(i, i * i)) punishment[i] = i * i;
        else punishment[i] = 0;
    }
    for(int i = 1; i <= 1000; i++) {
        punishment[i] += punishment[i - 1];
    }
    return 0;
}();

class Solution {
public:
    int punishmentNumber(int n) {
        return punishment[n];
    }
};
