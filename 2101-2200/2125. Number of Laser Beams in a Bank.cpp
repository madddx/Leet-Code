class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt = 0;
        int prev = 0;
        int ans = 0;
        for (int i = 0; i < bank.size(); i++){
            cnt = 0;

            for (char c : bank[i]){
                if (c == '1'){
                    cnt++;
                }
            }

            if (cnt > 0){
                ans += cnt * prev;
                prev = cnt;
            }
        }
        return ans;
    }
};
