static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    auto ball_to_color = unordered_map<int, int>{};
    auto color_counts = unordered_map<int, int>{};
    auto num_colors = 0;
    auto result = vector<int>{};
    result.reserve(size(queries));
    for (const auto& query : queries) {
      auto [ball, color] = make_pair(query[0], query[1]);
      auto& color_assignment = ball_to_color[ball];
      if (color_assignment) {
        if (--color_counts[color_assignment] == 0) --num_colors;
      }
      color_assignment = color;
      if (++color_counts[color] == 1) ++num_colors;
      result.push_back(num_colors);
    }
    return result;
  }
};
