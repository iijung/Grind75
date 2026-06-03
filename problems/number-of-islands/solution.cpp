// https://leetcode.com/problems/number-of-islands/

class Solution {
private:
    static constexpr char WATER = '0';
    static constexpr char LAND = '1';

    bool is_range(vector<vector<char>>& grid, int row, int col) {
        return 0 <= row && row < grid.size() && 0 <= col && col < grid[row].size();
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (size_t row = 0; row < grid.size(); row++) {
            for (size_t col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == WATER)
                    continue;
                count++;
                // dfs(grid, row, col);
                bfs(grid, row, col);
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (!is_range(grid, row, col) || grid[row][col] == WATER)
            return;
        grid[row][col] = WATER;
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
    }

    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            const auto [r, c] = q.front();
            q.pop();
            if (!is_range(grid, r, c) || grid[r][c] == WATER)
                continue;
            grid[r][c] = WATER;
            q.push({r - 1, c});
            q.push({r + 1, c});
            q.push({r, c - 1});
            q.push({r, c + 1});
        }
    }
};
