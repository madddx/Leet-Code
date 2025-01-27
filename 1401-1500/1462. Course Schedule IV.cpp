static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    auto prereq_for = vector<vector<int>>(numCourses);
    for (const auto& prereq : prerequisites)
        prereq_for[prereq.front()].push_back(prereq.back());
    auto memo = vector<bitset<101>>(numCourses, not_evaluated);

    auto answer = vector<bool>{};
    answer.reserve(size(queries));
    for (auto& query : queries) {
      auto course1 = query.front();
      auto course2 = query.back();
      answer.push_back(evaluate_prereq_query(
        course1, course2, memo, prereq_for));
    }
    return answer;
  }
private:
  constexpr static auto not_evaluated = bitset<101>(1) << 100;
  bool evaluate_prereq_query(int course1, int course2, vector<bitset<101>>& memo,
      const vector<vector<int>>& prereq_for) {
      return prereq_for_set(course1, memo, prereq_for)[course2];
   }

  bitset<101>& prereq_for_set(int course, vector<bitset<101>>& memo,
      const vector<vector<int>>& prereq_for) {
    auto& prereq_set = memo[course];
    if (prereq_set != not_evaluated) return prereq_set;

    prereq_set.reset();
    for (auto dependent_course : prereq_for[course]) {
      prereq_set.set(dependent_course);
      prereq_set |= prereq_for_set(dependent_course, memo, prereq_for);
    }
    return prereq_set;
  }
};
