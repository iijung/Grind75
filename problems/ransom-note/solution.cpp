// https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int alphabet[26] = {0};
        for (int i = 0; i < magazine.length(); ++i)
            alphabet[magazine[i] - 'a']++;
        for (int i = 0; i < ransomNote.length(); ++i) {
            const char idx = ransomNote[i] - 'a';
            if (alphabet[idx] == 0)
                return false;
            alphabet[idx]--;
        }
        return true;
    }
};
