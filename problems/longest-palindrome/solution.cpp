// https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        int alpabet[2][26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            if (isupper(s[i])) {
                alpabet[0][s[i] - 'A']++;
            } else {
                alpabet[1][s[i] - 'a']++;
            }
        }
        int length = 0;
        bool can_add = false;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 26; ++j) {
                length += alpabet[i][j] / 2 * 2;
                if (alpabet[i][j] % 2)
                    can_add = true;
            }
        }
        return length + (can_add? 1 : 0);
    }
};
