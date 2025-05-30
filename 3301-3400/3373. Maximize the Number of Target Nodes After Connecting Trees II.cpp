class Solution {
    vector<vector<int>> adj;
    vector<int> vis;

public:
    int buildGraph(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        
        adj.assign(n, {});
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vis.assign(n, -1);

        return n;
    }

    void dfs(int cn, int p, int curr) {
        vis[cn] = curr;
        for (int& nn : adj[cn]) {
            if (nn != p) {
                dfs(nn, cn, curr ^ 1);
            }
        }
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = buildGraph(edges2);
        dfs(0, n, 0);
        int o = 0;
        int e = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                e++;
            } else {
                o++;
            }
        }
        int maxi = max(o, e);

        n = buildGraph(edges1);
        dfs(0, n, 0);
        o = e = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                e++;
            } else {
                o++;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                res.push_back(e + maxi);
            } else {
                res.push_back(o + maxi);
            }
        }
        return res;
    }
};
