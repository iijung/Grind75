// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        for (int i = 0; i <= n; ++i)
            result[i] = popcount(i);
        return result;
    }
private:
    int popcount(int n) {
        n = (n & 0x55555555) + (n >> 1 & 0x55555555);
        n = (n & 0x33333333) + (n >> 2 & 0x33333333);
        n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);
        n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);
        return n;
    }
};
