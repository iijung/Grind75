// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        string palindrome = "";
        for (const char& c : s) {
            if (isalnum(c)) {
                palindrome += tolower(c);
            }
        }
        const int len = palindrome.size();
        const int mid = len / 2;
        for (int i = 0; i < mid; ++i) {
            if (palindrome[i] != palindrome[len - i - 1])
                return false;
        }
        return true;
    }
};
