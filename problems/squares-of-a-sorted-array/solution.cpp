// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        int curr = nums.size() - 1;
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[curr--] = nums[left] * nums[left];
                left++;
            } else {
                result[curr--] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};
