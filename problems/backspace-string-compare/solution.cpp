// https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_stack;
        for (const char& c: s) {
            if (c != '#')
                s_stack.push(c);
            else if (!s_stack.empty())
                s_stack.pop();
        }
        stack<char> t_stack;
        for (const char& c: t) {
            if (c != '#')
                t_stack.push(c);
            else if (!t_stack.empty())
                t_stack.pop();
        }
        while (!s_stack.empty() && !t_stack.empty()) {
            if (s_stack.top() != t_stack.top())
                return false;
            s_stack.pop();
            t_stack.pop();
        }
        return s_stack.empty() && t_stack.empty();
    }
};
