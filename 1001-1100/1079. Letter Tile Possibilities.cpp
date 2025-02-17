class Solution {
public:
void backtrack(unordered_map<char,int>&mapi,int &count){
    for(auto&entry:mapi){
    if(entry.second>0){
        entry.second--;
        count++;
        backtrack(mapi,count);
        entry.second++;
    }
    }
}
    int numTilePossibilities(string tiles) {
        unordered_map<char,int>mapi;
        for(int i=0;i<tiles.size();i++){
            mapi[tiles[i]]++;
        }
        int count=0;
         backtrack(mapi,count);
         return count;
    }
};
