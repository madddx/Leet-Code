class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int col_len = heights.size();          // satır sayısı (m)
        int row_len = heights[0].size();       // sütun sayısı (n)
        vector<pair<int,int>> all_directions{{0,1},{0,-1},{1,0},{-1,0}};
        queue<tuple<int,int,int>> next_cell;   // (r, c, ocean) 1=Pacific, 2=Atlantic
        vector<vector<int>> visited(col_len, vector<int>(row_len, 0)); // bitmask: 1|2

        auto enqueue_if_new = [&](int r, int c, int ocean){
            if ((visited[r][c] & ocean) == 0) {   // bu okyanat için henüz işaretlenmemişse
                visited[r][c] |= ocean;
                next_cell.emplace(r, c, ocean);
            }
        };

        // Top (Pacific)
        for (int c = 0; c < row_len; ++c) enqueue_if_new(0, c, 1);
        // Left (Pacific)
        for (int r = 0; r < col_len; ++r) enqueue_if_new(r, 0, 1);

        // Right (Atlantic)
        for (int r = 0; r < col_len; ++r) enqueue_if_new(r, row_len - 1, 2);

        // Bottom (Atlantic)  <-- burası sendeki hataydı
        for (int c = 0; c < row_len; ++c) enqueue_if_new(col_len - 1, c, 2);

        while (!next_cell.empty()) {
            auto [row, col, ocean_from] = next_cell.front();
            next_cell.pop();

            for (auto [dx, dy] : all_directions) {
                int nr = row + dx, nc = col + dy;
                if (!is_valid(nr, nc, heights)) continue;

                // Okyanattan içeri doğru "tırmanıyoruz": komşu >= mevcut olmalı
                if (heights[nr][nc] >= heights[row][col]) {
                    if (!is_visited(nr, nc, ocean_from, visited)) { // bu okyanat için ziyaret edilmemişse
                        visited[nr][nc] |= ocean_from;               // <-- komşuyu işaretle
                        next_cell.emplace(nr, nc, ocean_from);
                    }
                }
            }
        }

        vector<vector<int>> result;
        for (int r = 0; r < col_len; ++r)
            for (int c = 0; c < row_len; ++c)
                if (visited[r][c] == 3)
                    result.push_back({r, c});

        return result;
    }

private:
    bool is_valid(int row, int col, const vector<vector<int>>& heights) {
        return row >= 0 && col >= 0 && row < (int)heights.size() && col < (int)heights[0].size();
    }

    // Bu fonksiyonu "bitmask" mantığına göre düzelttim
    bool is_visited(int row, int col, int from_ocean, const vector<vector<int>>& visited) {
        return (visited[row][col] & from_ocean) != 0;
    }
};
