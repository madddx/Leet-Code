class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int m=capacity.size(), az=reduce(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end());
        int cnt=0;
        for(int i=m-1; i>=0; i--){
            az-=capacity[i];
            cnt++;
            if (az<=0) return cnt;
        }
        return -1;// never reach
    }
};
