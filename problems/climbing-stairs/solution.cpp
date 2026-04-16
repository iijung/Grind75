// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        if (n < 4)
            return n;
        if (cache[n] != 0)
            return cache[n];
        cache[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return cache[n];
    }
private:
    int cache[46] = {0, 1, 2, 3};
};
