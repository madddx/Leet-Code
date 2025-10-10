
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        vector<int> dp(energy.size(),-1);
        int ans=INT_MIN;
        for(int i=energy.size()-1;i>=0;i--)
        {
            if(i+k<energy.size())
            {
                dp[i]=energy[i]+dp[i+k];
            }
            else
            {
                dp[i]=energy[i];
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
