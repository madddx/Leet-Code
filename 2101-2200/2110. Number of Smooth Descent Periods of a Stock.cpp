class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        
        long long cnt = 0;
        long long currStreak = 1;
        long long prevPrice = -1;
        for(int price : prices)
        {
            if(price > 0 && (prevPrice - price) == 1)
            {
                currStreak++;
                cnt += currStreak;
            }else
            {
                currStreak = 1;
                cnt++;
            }

            // std::cout << prevPrice << " " << price << std::endl;
            prevPrice = price;
        }

        return cnt;
    }
};
