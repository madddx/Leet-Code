// class Solution {
// public:
//     int totalFruit(vector<int>& arr) {
//         //brute force
//         int maxcount=0;
//         unordered_map<int,int> t;
//          unordered_map<int,int> mp;
        
//         for(int i=0;i<arr.size();i++){
//             mp=t;
           
//             for(int j=i;j<arr.size();j++){
//                 mp[arr[j]]++;
//                 if(mp.size()<=2){
//                     maxcount=max(maxcount,j-i+1);
                   
//                 }
//                 else{
//                     break;
//                 }
//             }
//         }
//         return maxcount;
        
//     }
// };
//2nd approach using vsw variable isme hamlog basically k=2 diya hai condition aur map maintain kar rhe hai;
// class Solution {
// public:
//     int totalFruit(vector<int>& arr) {
//         if(arr.size()==1){
//             return 1;
//         }
//         int i=0,j=0,n=arr.size();
//         int maxcount=0;
//         unordered_map<int,int> mp;
//         while(j<n){
//             mp[arr[j]]++;
//             if(mp.size()<=2){
//                 maxcount=max(maxcount,j-i+1);
//             }
//             else{
//                 while(mp.size()>2){
//                     mp[arr[i]]--;
//                     if(mp[arr[i]]==0){
//                         mp.erase(arr[i]);
//                     }
//                     i++;

//                 }
//             }
//             j++;
//         }
//         return maxcount;
//     }
// };
class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int lastFruit = -1, secondLastFruit = -1;
int lastFruitCount = 0;
int maxCount = 0, curCount = 0;

for (int fruit : arr) {
    if (fruit == lastFruit || fruit == secondLastFruit) {
        curCount++;
    } else {
        curCount = lastFruitCount + 1;  // just last streak + new fruit
    }

    if (fruit == lastFruit) lastFruitCount++;
    else {
        lastFruitCount = 1;
        secondLastFruit = lastFruit;
        lastFruit = fruit;
    }

    maxCount = max(maxCount, curCount);
}
return maxCount;
    }
};
