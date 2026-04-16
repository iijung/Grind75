// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    MyQueue() {
    }

    void push(int x) {
        while(!main.empty()) {
            temp.push(main.top());
            main.pop();
        }
        main.push(x);
        while(!temp.empty()) {
            main.push(temp.top());
            temp.pop();
        }
    }

    int pop() {
        const int x = main.top();
        main.pop();
        return x;
    }

    int peek() {
        return main.top();
    }

    bool empty() {
        return main.empty();
    }
private:
   stack<int> main;
   stack<int> temp;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
