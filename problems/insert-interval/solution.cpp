// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int curr = 0;
        while (curr < intervals.size() && intervals[curr][1] < newInterval[0]) {
            result.push_back(intervals[curr]);
            curr++;
        }
        vector<int> interval = newInterval;
        while (curr < intervals.size() && intervals[curr][0] <= newInterval[1]) {
             interval[0] = min(interval[0], intervals[curr][0]);
             interval[1] = max(interval[1], intervals[curr][1]);
             curr++;
        }
        result.push_back(interval);
        while (curr < intervals.size()) {
            result.push_back(intervals[curr]);
            curr++;
        }
        return result;
    }
};
