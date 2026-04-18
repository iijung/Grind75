// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (const int& num: nums) {
            count[num]++;
        }
        const int mid = nums.size() / 2;
        for (const auto& [num, cnt]: count) {
            if (cnt > mid)
                return num;
        }
        return -1;
    }
};
