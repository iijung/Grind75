// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            const int target = -nums[i];

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                const int sum = nums[j] + nums[k];
                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else if (sum == target) {
                    const vector<int> triplet = {nums[i], nums[j], nums[k]};
                    result.push_back(triplet);
                    while (j < k && nums[j] == triplet[1]) j++;
                    while (j < k && nums[k] == triplet[2]) k--;
                }
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};
