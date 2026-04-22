// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int digit = 1;
        while (digit <= x / 10)
            digit *= 10;
        while (x) {
            if (x / digit != x % 10)
                return false;
            x %= digit;
            x /= 10;
            digit /= 100;
        }
        return true;
    }
};
