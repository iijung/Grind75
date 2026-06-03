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
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int count = 0;
        for (size_t row = 0; row < grid.size(); row++) {
            for (size_t col = 0; col < grid[row].size(); col++) {
                if (visited[row][col] || grid[row][col] == WATER)
                    continue;
                count++;
                // dfs(visited, grid, row, col);
                bfs(visited, grid, row, col);
            }
        }
        return count;
    }

    void dfs(vector<vector<bool>>& visited, vector<vector<char>>& grid, int row, int col) {
        if (!is_range(grid, row, col) || visited[row][col] || grid[row][col] == WATER)
            return;
        visited[row][col] = true;
        dfs(visited, grid, row - 1, col);
        dfs(visited, grid, row + 1, col);
        dfs(visited, grid, row, col - 1);
        dfs(visited, grid, row, col + 1);
    }

    void bfs(vector<vector<bool>> visited, vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty()) {
            const auto [r, c] = q.front();
            q.pop();
            if (!is_range(grid, r, c) || visited[r][c] || grid[r][c] == WATER)
                continue;
            visited[r][c] = true;
            q.push({r - 1, c});
            q.push({r + 1, c});
            q.push({r, c - 1});
            q.push({r, c + 1});
        }
    }
};
