// https://leetcode.com/problems/rotting-oranges/

class Solution {
private:
    static constexpr int EMPTY_CELL = 0;
    static constexpr int FRESH_ORANGE = 1;
    static constexpr int ROTTEN_ORANGE = 2;

    bool is_range(const vector<vector<int>>& grid, int row, int col) {
        return 0 <= row && row < grid.size() && 0 <= col && col < grid[row].size();
    }

public:
    int solve(vector<vector<int>>& grid, queue<pair<int, int>> rotten, int fresh_count) {
        int minutes = 0;
        while (!rotten.empty() && fresh_count > 0) {
            const size_t rotten_count = rotten.size();
            for (size_t i = 0; i < rotten_count; i++) {
                const auto [row, col] = rotten.front();
                rotten.pop();

                vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (const auto [dr, dc]: directions) {
                    const int next_row = row + dr;
                    const int next_col = col + dc;
                    if (!is_range(grid, next_row, next_col))
                        continue;
                    if (grid[next_row][next_col] != FRESH_ORANGE)
                        continue;
                    grid[next_row][next_col] = ROTTEN_ORANGE;
                    rotten.push({next_row, next_col});
                    fresh_count--;
                }
            }
            minutes++;
        }
        if (fresh_count > 0)
            return -1;
        return minutes;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int fresh_count = 0;
        for (size_t row = 0; row < grid.size(); row++) {
            for (size_t col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == FRESH_ORANGE)
                    fresh_count++;
                if (grid[row][col] == ROTTEN_ORANGE)
                    rotten.push({row, col});
            }
        }
        if (fresh_count == 0)
            return 0;
        if (rotten.empty())
            return -1;
        return solve(grid, rotten, fresh_count);
    }
};
