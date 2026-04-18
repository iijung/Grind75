// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "0" && b == "0")
            return "0";
        int i = 0;
        int carry = 0;
        string result = "";
        while (i < a.length() || i < b.length() || carry) {
             if (i < a.length())
                carry += a[a.length() - 1 - i] - '0';
            if (i < b.length())
                carry += b[b.length() - 1 - i] - '0';
            result = (carry & 1? "1" : "0") + result;
            carry /= 2;
            ++i;
        }
        return result;
    }
};
