#include <ranges>

class Solution {
public:
  int magnificentSets(int n, vector<vector<int>>& edges) {
    auto adj = vector<vector<int>>(n);
    for (const auto& edge : edges) {
      auto [u, v] = make_pair(edge.front(), edge.back());
      adj[u - 1].push_back(v - 1);
      adj[v - 1].push_back(u - 1);
    }

    auto node_color = vector<int>(n, uncolored);
    auto ccs = vector<vector<int>>{};
    for (auto u : views::iota(0, n)) {
      if (node_color[u] != uncolored) continue;
      if (!dfs(u, adj, black, node_color, ccs.emplace_back())) return -1;
    }

    return transform_reduce(begin(ccs), end(ccs), 0, plus{},
        [&adj](const auto& cc) { return max_groups_for_cc(cc, adj); } );
  }
private:
  static constexpr auto uncolored = -1;
  static constexpr auto black = 0;
  static constexpr auto white = 1;

  static bool dfs(int u, const vector<vector<int>>& adj, int color,
            vector<int>&node_color, vector<int>& cc) {
    auto complement = !color;
    node_color[u] = color;
    cc.push_back(u);
    for (auto v : adj[u]) {
      if (node_color[v] == color ||
          (node_color[v] == uncolored &&
           !dfs(v, adj, complement, node_color, cc)))
        return false;
    }
    return true;
  }

  static int max_groups_for_cc(const vector<int>& cc,
      const vector<vector<int>>& adj) {
    if (size(cc) == 1) return 1;

    auto q = vector<int>{};
    auto next_q = vector<int>{};
    auto max_groups = 0;
    for (auto start : cc) {
      q.push_back(start);
      auto seen = bitset<500>{1} << start;
      auto groups = 0;
      while (!empty(q)) {
        ++groups;
        for (auto u : q) {
          for (auto v : adj[u]) {
            if (seen[v]) continue;
            seen.set(v);
            next_q.push_back(v);
          }
        }
        swap(q, next_q);
        next_q.clear();
      }
      if (groups > max_groups) max_groups = groups;
    }
    return max_groups;
  }
};
