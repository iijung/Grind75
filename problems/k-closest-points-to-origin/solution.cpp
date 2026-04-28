// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> q;
        for (auto& point: points) {
            const double distance = hypot(point[0], point[1]);
            q.push({distance, point});
            if (q.size() > k)
                q.pop();
        }
        vector<vector<int>> result;
        while (!q.empty()) {
            const auto& [_, point] = q.top();
            result.push_back(point);
            q.pop();
        }
        return result;
    }
};
