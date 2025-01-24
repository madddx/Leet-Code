class Solution {
public:
    bool dfs(int node,vector<int> &visited,vector<int> &pathVisited,vector<int> &checked,vector<vector<int>> &graph)
    {
        visited[node]=1;
        pathVisited[node]=1;

        for(int nei : graph[node])
        {
            if(!visited[nei])
            {
                if(dfs(nei,visited,pathVisited,checked,graph))
                {
                    return true;
                }
            }
              else if(pathVisited[nei]==1)
                {
                    return true;
                }
        }
        checked[node]=1;
        pathVisited[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     int n = graph.size();
     vector<int> visited(n,0);
     vector<int> pathVisited(n,0);
     vector<int> checked(n,0);
     vector<int> safe;

     for(int i=0;i<n;i++)
     {
        if(!visited[i])
        {
            dfs(i,visited,pathVisited,checked,graph);
        }
     }

     for(int i=0;i<n;i++)
     {
        if(checked[i]==1)
        safe.push_back(i);
     }
     return safe;
    }
};
