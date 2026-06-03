// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    MinStack() {
    }

    void push(int val) {
        const int minimum = s.empty() ? val : min(getMin(), val);
        s.push({val, minimum});
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }

    stack<pair<int, int>> s;    // value, minimum
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
