

int v[100005], o[100005], d[100005], s[100005];

class Solution {
public:
    
    int maximumInvitations(vector<int>& a) {
        int n = a.size(), res1 = 0, res2 = 0;
        memset(v, 0, n * 4);
        memset(o, -1, n * 4);
        memset(d, 0, n * 4);
        memset(s, 0, n * 4);
        for(int i = 0; i < n; i++) {
            if(!v[i]) {
                int c = 0, f = 0;
                for(int j = i; ; j = a[j]) {
                    if(v[j]) {
                        if(o[j] >= 0) {
                            f = 1;
                            d[o[j]] = max(d[o[j]], s[j] + c);
                            for(int k = i; k != j; k = a[k], c--) {
                                o[k] = o[j];
                                s[k] = c + s[j];
                            }
                        } else {
                            if(o[j] == -1) {
                                c = 1;
                                for(int k = j; a[k] != j; k = a[k]) {
                                    c++;
                                }
                                res1 = max(res1, c);
                            }
                        }
                        break;
                    }
                    v[j] = 1;
                    c++;
                    if(a[a[j]] == j) {
                        d[a[j]] = c;
                        d[j] = max(d[j], 1);
                        for(int k = i; k != a[j]; k = a[k], c--) {
                            o[k] = a[j];
                            s[k] = c;
                        }
                        break;
                    }
                }
                if(!f) {
                    for(int k = i; o[k] == -1; k = a[k]) {
                        o[k] = -2;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(a[a[i]] == i && a[i] > i) {
                res2 += d[a[i]] + d[i];
            }
        }
        return max(res1, res2);
    }
};
