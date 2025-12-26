class Solution {
public:
    int bestClosingTime(string c) {
        int LN = 0;
        int totaly = 0;

        for(int i = 0;i<c.size();i++) {
            totaly += (c[i] == 'Y');
        }

        int Y = 0;
        int mpen = INT_MAX;
        int ans = 0;
        for(int i = 0;i<c.size();i++) {
            int RY = totaly-Y;
            int penalty = RY + LN;
            if (penalty < mpen) {
                ans = i;
                mpen = penalty;
            }
            Y += (c[i] == 'Y');
            LN += (c[i] == 'N');
        }
        int RY = totaly-Y;
        int penalty = RY + LN;
        if (penalty < mpen) {
            ans = c.size();
            mpen = penalty;
        }
        return ans;
    }
};

/*

YYNY



try to close at each and every hour and see if it incurs the minimum penalty 

close at 0 

count Y after 0 + Count N before 0 --> 3 

Count Y after 1 + Count N before 1 --> 2

Count Y after 2 + Count N before 2 --> 1

Count Y after 3 + Count N before 1 --> 2

Count Y after 4 + Count N before 0 --> 1

*/
