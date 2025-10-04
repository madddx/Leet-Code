class Solution {
public:
    int maxArea(vector<int>& height) {
        int width=height.size()-1;
        int ptr1=0;
        int ptr2=height.size()-1;
        int ans=0;
        while(ptr1<ptr2){
            int h=min(height[ptr1],height[ptr2]);
            ans=max(ans,h*width);
            width--;
            if(height[ptr1]>height[ptr2]){
                ptr2--;
            }
            else{
                ptr1++;
            }
        }
        return ans;
    }
};
