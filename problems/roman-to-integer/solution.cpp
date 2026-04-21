// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int integer = 0;
        for (int i = 0; i < s.length(); ++i) {
            const std::string sub = s.substr(i, 2);
            if (sub == "IV"     // 4
                || sub == "IX"  // 9
                || sub == "XL"  // 40
                || sub == "XC"  // 90
                || sub == "CD"  // 400
                || sub == "CM"  // 900
            ) {
                integer += roman[s[i + 1]] - roman[s[i]];
                ++i;
            } else {
                integer += roman[s[i]];
            }
        }
        return integer;
    }
};
