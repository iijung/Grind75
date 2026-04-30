#include <string>
#include <unordered_set>

using namespace std;

#include "solution.cpp"
#include <cassert>

int main() {
    assert(Solution().lengthOfLongestSubstring("abcabcbb") == 3);
    assert(Solution().lengthOfLongestSubstring("bbbbb") == 1);
    assert(Solution().lengthOfLongestSubstring("pwwkew") == 3);
    assert(Solution().lengthOfLongestSubstring(" ") == 1);
    assert(Solution().lengthOfLongestSubstring("aabaab!bb") == 3);
    assert(Solution().lengthOfLongestSubstring("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") == 55);
    return 0;
}
