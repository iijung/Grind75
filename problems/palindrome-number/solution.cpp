// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
#if 0
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
#else
        const unsigned int org = x;
        unsigned int palindrome = 0;
        while (x) {
            palindrome = palindrome * 10 + x % 10;
            x /= 10;
        }
        return palindrome == org;
#endif
    }
};
