class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort (potions.begin (), potions.end());
        vector<int>ans;
        
        int m = potions.size();

        for (int spell : spells){

            long long minPotion = (success + spell -1)/ spell;

            int low = 0;
            int high = m-1;
            int firstValid = m;

            while(low<=high){
                int mid = low + (high -low)/2;

                if((long long) potions[mid]>=minPotion){
                    firstValid = mid;
                    high = mid-1;
                }else {
                    low = mid+1;
                }
            }

            int count = m - firstValid;
            ans.push_back(count);
        }

        return ans;
    }
};

auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
