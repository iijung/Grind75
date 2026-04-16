// https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> alphabet;
        for (int i = 0; i < s.length(); ++i) {
            alphabet[s[i]]++;
        }
        int length = 0;
        bool can_add = false;
        for (const auto& [ch, cnt]: alphabet) {
            length += cnt / 2 * 2;
            if (cnt % 2)
                can_add = true;
        }
        return length + can_add;
    }
};
