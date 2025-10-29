class Solution {
public:
    int smallestNumber(int n) {
        while(1)
        {
            int a=n;
            while(a!=0)
            {
                int rem=a%2;
                if(rem==0) break;
                a/=2;
            }
            if(a==0) return n;
            n++;
        }
    }
};
