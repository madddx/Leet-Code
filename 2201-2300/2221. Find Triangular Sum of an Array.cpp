#include <ranges>

inline int add_mod(int a, int b) {
  auto sum = a + b;
  if (sum >= 10) sum -= 10;
  return sum;
}

array<vector<int>, 1'001> make_coefficients() {
  array<vector<int>, 1'001> coefficients = {};
  coefficients[1] = {1};
  for (auto i : views::iota(2, 1'001)) {
    auto& prev_row = coefficients[i - 1];
    auto& row = coefficients[i];
    row.resize(i);
    row[0] = 1;
    for (auto j : views::iota(1, i - 1)) {
      row[j] = add_mod(prev_row[j - 1], prev_row[j]);
    }
    row[i - 1] = 1;
  }
  return coefficients;
}

array<vector<int>, 1'001> coefficients = make_coefficients();

class Solution {
public:
  int triangularSum(vector<int>& nums) {
    auto sum = 0;
    for (auto [num, coefficient] : views::zip(nums, coefficients[size(nums)])) {
      sum = add_mod(sum, (num * coefficient) % 10);
    }
    return sum;
  }
};
