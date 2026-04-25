// https://leetcode.com/problems/01-matrix/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        for (int m = 0; m < mat.size(); m++) {
            for (int n = 0; n < mat[m].size(); n++) {
                if (mat[m][n])
                    mat[m][n] = INT_MAX;
                else
                    q.push({m, n});
            }
        }
        const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto [m, n] = q.front();
            q.pop();
            for (auto dir : directions) {
                const int new_m = m + dir.first;
                const int new_n = n + dir.second;
                if (new_m < 0 || new_m > mat.size() - 1)
                    continue;
                if (new_n < 0 || new_n > mat[m].size() - 1)
                    continue;
                if (mat[new_m][new_n] - 1 <= mat[m][n])
                    continue;
                mat[new_m][new_n] = mat[m][n] + 1;
                q.push({new_m, new_n});
            }
        }
        return  mat;
    }
};
