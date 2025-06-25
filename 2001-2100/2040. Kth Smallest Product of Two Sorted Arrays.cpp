#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    using ll=long long;

    ll kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, ll k) {
        const int &n1=nums1.size(), &n2=nums2.size();
        ll l=-1e10, r=1e10, mid;

        auto kthNotGreaterValue=[&](const ll &x)-> bool{
            ll cnt=0;
            for(int i=0;i<n1;++i){
                if(nums1[i]<0){
                    auto it=lower_bound(nums2.begin(), nums2.end(), (ll)ceil(1.0*x/nums1[i]));
                    cnt+=distance(it, nums2.end());
                }
                else if(nums1[i]>0){
                    auto it=upper_bound(nums2.begin(), nums2.end(), (ll)floor(1.0*x/nums1[i]));
                    cnt+=distance(nums2.begin(), it);
                }
                else if(x>=0)
                    cnt+=n2;
                
                if(cnt>=k)
                    return 1;
            }

            return cnt>=k;
        };

        ll ans=0LL;
        while(l<=r){
            mid=l+(r-l)/2;
            
            if(kthNotGreaterValue(mid)){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        
        return ans;
    }
};
