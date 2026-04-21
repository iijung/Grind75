// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int prefix_len = 0;
        while (!strs.empty() && prefix_len < strs[0].length()) {
            const char& c = strs[0][prefix_len];
            for (int i = 1; i < strs.size(); ++i) {
                if (c != strs[i][prefix_len])
                    goto FINISH;
            }
            prefix_len++;
        }
FINISH:
        return strs[0].substr(0, prefix_len);
    }
};
