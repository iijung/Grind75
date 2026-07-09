// https://leetcode.com/problems/permutations/

class Solution {
public:
#if 0
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        do {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return result;
    }
#else
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {{}};
        }
        if (nums.size() == 1) {
            return {{nums}};
        }
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> remain;
            for (const int& x: nums) {
                if (nums[i] != x)
                    remain.push_back(x);
            }
            for (auto sub: permute(remain)) {
                sub.push_back(nums[i]);
                result.push_back(sub);
            }
        }
        return result;
    }
#endif
};
