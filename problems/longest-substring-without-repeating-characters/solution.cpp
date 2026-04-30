// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest_length = 0;
        for (int curr = 0; curr < s.length(); ++curr) {
            int length = 0;
            unordered_set<char> seen;
            while (curr + length < s.length()) {
                if (seen.count(s[curr + length]))
                    break;
                seen.insert(s[curr + length]);
                ++length;
            }
            longest_length = max(longest_length, length);
        }
        return longest_length;
    }
};
