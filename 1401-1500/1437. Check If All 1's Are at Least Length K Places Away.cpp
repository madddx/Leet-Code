class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int val=0;
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]==1)
            {
                break;
            }
            i++;
        }
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]==1)
            {
                if(val<k)
                {
                    return false;
                }
                    val=0;
            }
            else
            {
                val++;
            }
        }return true;
    }
};
