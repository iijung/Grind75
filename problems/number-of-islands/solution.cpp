// https://leetcode.com/problems/number-of-islands/

class Solution {
private:
    static constexpr char WATER = '0';
    static constexpr char LAND = '1';

public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        return dfs(visited, grid, 0, 0);
    }

    int dfs_recur(vector<vector<bool>>& visited, vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size())
            return 0;
        if (visited[row][col] || grid[row][col] == WATER)
            return 0;
        visited[row][col] = true;
        dfs_recur(visited, grid, row - 1, col);
        dfs_recur(visited, grid, row + 1, col);
        dfs_recur(visited, grid, row, col - 1);
        dfs_recur(visited, grid, row, col + 1);
        return 1;
    }

    int dfs(vector<vector<bool>> visited, vector<vector<char>>& grid, int row, int col) {
        int count = 0;
        for (size_t row = 0; row < grid.size(); row++) {
            for (size_t col = 0; col < grid[row].size(); col++) {
                if (!visited[row][col] && grid[row][col] == LAND)
                    count += dfs_recur(visited, grid, row, col);
            }
        }
        return count;
    }

    int bfs(vector<vector<bool>> visited, vector<vector<char>>& grid) {
        int count = 0;
        for (size_t row = 0; row < grid.size(); row++) {
            for (size_t col = 0; col < grid[row].size(); col++) {
                if (visited[row][col] || grid[row][col] == WATER)
                    continue;
                count++;
                queue<pair<int, int>> q;
                q.push({row, col});
                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
                    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[r].size())
                        continue;
                    if (visited[r][c] || grid[r][c] == WATER)
                        continue;
                    visited[r][c] = true;
                    q.push({r - 1, c});
                    q.push({r + 1, c});
                    q.push({r, c - 1});
                    q.push({r, c + 1});
                }
            }
        }
        return count;
    }
};
