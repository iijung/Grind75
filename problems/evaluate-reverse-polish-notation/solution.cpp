// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int calc(stack<int>& rpn, const char op) {
        assert(rpn.size() >= 2 && "insufficient operands for operator");
        const int num2 = rpn.top(); rpn.pop();
        const int num1 = rpn.top(); rpn.pop();
        switch (op) {
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '*': return num1 * num2;
            case '/': {
                assert(num2 != 0 && "division by zero");
                return num1 / num2;
            }
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> rpn; // reverse polish notation
        for (const string& token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/")
                rpn.push(calc(rpn, token[0]));
            else
                rpn.push(stoi(token));
        }
        assert(rpn.size() == 1 && "invalid reverse polish notation");
        return rpn.top();
};
