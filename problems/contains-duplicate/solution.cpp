// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> is_exist;
        for (const int& num: nums) {
            if (is_exist[num])
                return true;
            is_exist[num] = true;
        }
        return false;
    }
};
