class Solution {
public:
    string smallestNumber(string& pattern) {
        const int n=pattern.size();
        vector<char> succD(n, 0);
        succD.back()+=(pattern.back()=='D');
        for(int i=n-2; i>=0; i--)//O(n)
            succD[i]=(pattern[i]=='D')?succD[i+1]+1:0;
        string ans(n+1, ' ');// O(n)
        iota(ans.begin(), ans.end(), '1');//O(n)
        for(int i=0; i<n; i++){//O(n)
            if (pattern[i]=='D'){
                reverse(ans.begin()+i, ans.begin()+i+1+succD[i]);
            }
            i+=succD[i];// jump i
        }
        return ans;
    }
};
