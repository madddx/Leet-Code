class Solution {
public:
    bool valid(double a,double b){
        return fabs(a+b-24.0)<0.0001 | fabs(a-b-24.0)<0.0001 | fabs(a*b-24.0)<0.0001 | (b!=0 and fabs(a/b-24.0)<0.0001);
    }
    bool valid(double a,double b,double c){
        return valid(a+b,c) |valid(a,b+c) |valid(a-b,c)|valid(a,b-c)|valid(a*b,c)|valid(a,b*c)|valid(a/b,c)|valid(a,b/c);
    }
    bool get_perumutation(int idx,vector<double>& card){
        if(idx==4){
           return valid(card[0]+card[1],card[2],card[3]) |
                    valid(card[0],card[1]+card[2],card[3]) |
                    valid(card[0],card[1],card[2]+card[3]) |
                    valid(card[0]-card[1],card[2],card[3]) |
                    valid(card[0],card[1]-card[2],card[3]) |
                    valid(card[0],card[1],card[2]-card[3]) |
                    valid(card[0]*card[1],card[2],card[3]) |
                    valid(card[0],card[1]*card[2],card[3]) |
                    valid(card[0],card[1],card[2]*card[3]) |
                    valid(card[0]/card[1],card[2],card[3]) |
                    valid(card[0],card[1]/card[2],card[3]) |
                    valid(card[0],card[1],card[2]/card[3]);

        }
        int res=false;
        unordered_set<int> s;
        for(int i=idx;i<4 and !res;i++){
            if(s.count(card[i]))
                continue;
            s.insert(card[i]);
            swap(card[i],card[idx]);
            res|=get_perumutation(idx+1,card);
            swap(card[i],card[idx]);
        }
        return res;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> card;
        int n=cards.size();
        for(int i=0;i<n;i++){
            card.push_back((double)cards[i]);
        }
        return get_perumutation(0,card);
    }
};
