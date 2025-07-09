class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& et) {
         int n = st.size();
        vector<int> gaps(n + 1);

        // Compute gaps
        gaps[0] = st[0];  
        gaps[n] = eventTime - et[n - 1];  
        for(int i = 1; i < n; i++){
            gaps[i] = st[i] - et[i - 1];
        }

        // Sliding window of size k + 1
        int window = 0;
        for(int i = 0; i <= k; i++){
            window += gaps[i];
        }

        int ans = window;
        for(int i = k + 1; i <= n; i++){
            window += gaps[i] - gaps[i - (k + 1)];
            ans = max(ans, window);
        }

        return ans;
    }
};
