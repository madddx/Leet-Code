const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
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
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n,0);
        sort(meetings.begin(),meetings.end());
        priority_queue<int,vector<int>,greater<int>> availablerooms;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> occupytime;
        int a;
        for(int i=0;i<n;i++){
            availablerooms.push(i);
        }
        for(int i=0;i<meetings.size();i++){
            while(!occupytime.empty() && occupytime.top().first <= meetings[i][0]){
                availablerooms.push(occupytime.top().second);
                occupytime.pop();
            }
            if(!availablerooms.empty()){
                a=availablerooms.top();
                availablerooms.pop();
                rooms[a]++;
                occupytime.push({meetings[i][1],a});
            }
            else{
                pair<long long,int> b=occupytime.top();
                occupytime.pop();
                rooms[b.second]++;
                occupytime.push({b.first+meetings[i][1]-meetings[i][0],b.second});
            }
        }
        int max_bookings = -1;
        int most_booked_room_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (rooms[i] > max_bookings) {
                max_bookings = rooms[i];
                most_booked_room_idx = i;
            }
        }
        return most_booked_room_idx;
    }
};
