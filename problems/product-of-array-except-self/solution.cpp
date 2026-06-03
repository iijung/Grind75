// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);

        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] * nums[i];
        }

        const int end = nums.size() - 1;
        suffix[end] = nums[end];
        for (int i = end - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i != 0)
                result[i] *= prefix[i - 1];
            if (i != nums.size() - 1)
                result[i] *= suffix[i + 1];
        }
        return result;
    }
};
