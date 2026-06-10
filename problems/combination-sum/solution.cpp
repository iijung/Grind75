// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<vector<int>>> dp(target + 1);
        dp[0] = {{}};
        for (const int x: candidates) {
            for (int sum = x; sum <= target; sum++) {
                for (auto sub: dp[sum - x]) {
                    sub.push_back(x);
                    dp[sum].push_back(sub);
                }
            }
        }
        return dp[target];
    }
};
