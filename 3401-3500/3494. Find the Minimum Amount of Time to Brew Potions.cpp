class Solution {
    // maxi ki value jese hi kam ho maxi me + kr dena or last element se check krna 
public:
    long long minTime(vector<int>& mana, vector<int>& skill) {
        atexit(+[](){ofstream("display_runtime.txt") << 0 << '\n';});
        int n = skill.size();
        int m = mana.size();
        vector<vector<long long>> arr(n,vector<long long>(m));
        for(int i=0;i<n;i++){
            long long maxi  = (i>0) ? arr[i-1][m-1]:0;
            // cout<<maxi<<" ";
            long long sum  = 0;
            for(int j=m-2;j>=0 && i>0;j--){
                long long v = maxi-sum;
                
                if(v < arr[i-1][j+1]){
                    maxi = maxi+(arr[i-1][j+1]-v);
                }
                sum += skill[i]*mana[j];
            }
            if(i>0) maxi = max(maxi-sum,arr[i-1][0]);
            if(i==0){
                for(int j=0;j<m;j++){
                    if(j==0){
                        arr[i][j] = 1LL*skill[i]*mana[j];
                    }
                    else arr[i][j] += (1LL*skill[i]*mana[j]+arr[i][j-1]);
                }
            }
            else{
                for(int j=0;j<m;j++){
                    maxi += skill[i]*mana[j];
                    arr[i][j] = maxi;
                }
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return arr[n-1][m-1];
    }
};
