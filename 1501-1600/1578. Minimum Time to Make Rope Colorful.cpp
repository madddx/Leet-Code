class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        if(colors.size() == 1){
            return 0;
        }
        int i = 0;
        int j = i+1;
        int ans = 0;
        while(j<colors.size()){
            if(colors[i] == colors[j]){
                if(neededTime[i]<=neededTime[j]){
                    ans+=neededTime[i];
                    i=j;
                    j++;
                }
                else{
                    ans+=neededTime[j];
                    j++;
                }
            }
            else{
                i=j;
                j++;
            }
        }
        return ans;
    }
};
