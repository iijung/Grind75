// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);

        int prefix = 1;
        int suffix = 1;
        for (int l = 0; l < nums.size(); l++) {
            const int r = nums.size() - 1 - l;
            result[l] *= prefix;
            prefix *= nums[l];
            result[r] *= suffix;
            suffix *= nums[r];
        }
        return result;
    }
};
