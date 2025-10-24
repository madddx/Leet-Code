#define ll long long
class Solution {
public:
    ll rec(ll n,ll cur,ll len,vector<ll> &ct){
        if(len==0){
            if(cur>n){
                for(int i=1;i<10;i++){
                    if(ct[i]!=i && ct[i]>0) return 0;
                }
                return cur;
            }
            return 0;
        }
        ll ans=0;
        for(int i=1;i<10 && ans==0;i++){
            if(ct[i]<i && i-ct[i]<=len){
                ct[i]++;
                ans=rec(n,cur*10+i,len-1,ct);
                ct[i]--;
            }
        }
        return ans;
    }
    int nextBeautifulNumber(int n) {
        string s=to_string(n);
        ll m=s.size();
        vector<ll> ct(10,0);
        ll ans=rec(n,0,m,ct);
        ct.assign(10,0);
        ll x=rec(0,0,m+1,ct);
        if(ans==0) ans=x;
        return ans;
    }
};
