class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();long long t,nt;
        vector<long long> d(n,-1);
        d[n-1]=questions[n-1][0];
        for(int i=n-2;i>=0;i--){
            t=questions[i][0];
            if(i+questions[i][1]+1<n){
                t+=d[i+questions[i][1]+1];
            }
            nt=d[i+1];
            d[i]=max(t,nt);
        }
        return d[0];
        //return h(0,questions.size(),questions,d);
    }
private:
    long long h(int i,int n,vector<vector<int>>& q,vector<long long>& d){
        if(i>=n)return 0;
        if(d[i]!=-1)return d[i];
        return d[i]=max(h(i+1,n,q,d),q[i][0]+h(i+q[i][1]+1,n,q,d));
    }
};
