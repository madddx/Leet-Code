class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>visit(n, vector<int>(n,0));

        pq.push({grid[0][0],{0,0}});
        int ans = 0;
        vector<int>dirx{1,-1,0,0};
        vector<int>diry{0,0,1,-1};

        while(!pq.empty()){
            auto it = pq.top();
            int elevate = it.first;
            int xcor = it.second.first;
            int ycor = it.second.second;

            if(xcor==n-1 && ycor == n-1) return elevate;
            pq.pop();

            for(int i=0; i<4; i++){
                int newx = xcor + dirx[i];
                int newy = ycor + diry[i];

                if(newx<0 || newx>=n || newy<0 || newy>=n || visit[newx][newy])continue;
                visit[newx][newy] = 1;
                pq.push({max(elevate, grid[newx][newy]), {newx, newy}});
                

            }
        }
        return ans;
    }
};
