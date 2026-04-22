// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr = 0;
        int check = 0;
        while (check < nums.size()) {
            if (nums[check] != 0) {
                nums[curr] = nums[check];
                curr++;
            }
            check++;
        }
        while (curr < nums.size()) {
            nums[curr] = 0;
            curr++;
        }
    }
};
