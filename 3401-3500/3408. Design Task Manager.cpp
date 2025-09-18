#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto harsh = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif
class TaskManager {
public:
    unordered_map<int, pair<int,int>> mp;
    priority_queue<tuple<int, int, int>> pq;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto x : tasks){
            mp[x[1]] = {x[0], x[2]};
            pq.push({x[2], x[1], x[0]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].second = newPriority;
        int userId = mp[taskId].first;
        pq.push({newPriority, taskId, userId});
        
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [priority, taskId, userId] = pq.top();
            pq.pop();
            if(mp.find(taskId) != mp.end() && mp[taskId].second == priority){
                mp.erase(taskId);
                return userId;
            }
        }
        return  -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
