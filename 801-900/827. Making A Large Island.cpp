#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,abm,bmi2")

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

// class Solution {
//   public:
//     int largestIsland(std::vector<std::vector<int>> &grid) {
//         int groupId = -1, n = grid.size();
//         int groupSize[n * n + 1];
//         std::memset(groupSize, 0, sizeof(groupSize));

//         auto dfs = [&](this auto &&dfs, int i, int j) -> int {
//             if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] < 1) {
//                 return 0;
//             }
//             grid[i][j] = groupId;
//             return 1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1);
//         };

//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] > 0) {
//                     groupSize[~(groupId - 1)] = dfs(i, j);
//                     --groupId;
//                 }
//             }
//         }

//         int res = 0;
//         std::unordered_set<int> check;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (grid[i][j] == 0) {
//                     check.clear();
//                     int cur = 1;
//                     if (i - 1 >= 0 && check.insert(grid[i - 1][j]).second) {
//                         cur += groupSize[~(grid[i - 1][j] - 1)];
//                     }
//                     if (i + 1 < n && check.insert(grid[i + 1][j]).second) {
//                         cur += groupSize[~(grid[i + 1][j] - 1)];
//                     }
//                     if (j - 1 >= 0 && check.insert(grid[i][j - 1]).second) {
//                         cur += groupSize[~(grid[i][j - 1] - 1)];
//                     }
//                     if (j + 1 < n && check.insert(grid[i][j + 1]).second) {
//                         cur += groupSize[~(grid[i][j + 1] - 1)];
//                     }
//                     res = std::max(res, cur);
//                 }
//             }
//         }

//         return res == 0 ? n * n : res;
//     }
// };

class Solution {
  public:
    int largestIsland(std::vector<std::vector<int>> &grid) {
        int groupId = -1, n = grid.size();
        int groupSize[n * n + 1];
        std::memset(groupSize, 0, sizeof(groupSize));

        auto dfs = [&](this auto &&dfs, int i, int j) -> int {
            if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] < 1) {
                return 0;
            }
            grid[i][j] = groupId;
            return 1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1);
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    groupSize[~(groupId - 1)] = dfs(i, j);
                    --groupId;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int cur = 1;
                    int a = (i > 0) ? grid[i - 1][j] : 0;
                    int b = (i + 1 < n) ? grid[i + 1][j] : 0;
                    int c = (j > 0) ? grid[i][j - 1] : 0;
                    int d = (j + 1 < n) ? grid[i][j + 1] : 0;
                    if (a != 0) {
                        cur += groupSize[~(grid[i - 1][j] - 1)];
                    }
                    if (b != 0 && b != a) {
                        cur += groupSize[~(grid[i + 1][j] - 1)];
                    }
                    if (c != 0 && c != a && c != b) {
                        cur += groupSize[~(grid[i][j - 1] - 1)];
                    }
                    if (d != 0 && d != a && d != b && d != c) {
                        cur += groupSize[~(grid[i][j + 1] - 1)];
                    }
                    res = std::max(res, cur);
                }
            }
        }

        return res == 0 ? n * n : res;
    }
};
