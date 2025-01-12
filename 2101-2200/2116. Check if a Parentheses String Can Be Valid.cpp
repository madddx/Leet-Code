class Solution {
public:
    bool canBeValid(string s, string locked) {
        int left = 0, right = 0, free = 0;
        int n = s.size();
        if((n % 2) != 0)
            return false;
        for(int i = 0; i < n; i++) {
            if(locked[i] == '0')
                free++;
            else if(s[i] == '(')
                left++;
            else
                right++;
            if(right - left > free)
                return false;
        }
        left = right = free = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(locked[i] == '0')
                free++;
            else if(s[i] == '(')
                left++;
            else
                right++;
            if(left - right > free)
                return false;
        }
        return true;
    }
};
