// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (const char& c: s) {
            if (c == '(' || c == '{' || c == '[')
                stack.push(c);
            else if (stack.empty())
                return false;
            else if (c == ')' && (stack.top() != '('))
                return false;
            else if (c == '}' && (stack.top() != '{'))
                return false;
            else if (c == ']' && (stack.top() != '['))
                return false;
            else
                stack.pop();
        }
        return stack.empty();
    }
};
