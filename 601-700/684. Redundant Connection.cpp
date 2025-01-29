class Solution {
public:
    
    int findPar(int p,vector<int>par){
        if(p==par[p]){
            return p;
        }
        return findPar(par[p],par);
    }//for finding the parent of a node in a given graph 
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
          vector<int> p(2000, 0);
        for(int i = 0; i < p.size(); i++ )
            p[i] = i;//parent vector taken initialised with a vaalue 
        
        vector<int> res;//res vector 
        for(auto v : edges ){
            int n1 = v[0], n2 = v[1];//n1 and n2 2 nodes taken 
            while(n1 != p[n1]) n1 = p[n1];//while n1 is not the parent of n1 then we initialise with parent p[n1]
            while(n2 != p[n2]) n2 = p[n2];//same goes with the n2 
            if( n1 == n2 )//if both r same it is a possible edge which can be removed for making it a tree
                res = v;
            else//else we join n1 to n2 and make n2 the paren tof n1 
                p[n1] = n2;
        }//TC IS O(N)
        return res;
    }
};
