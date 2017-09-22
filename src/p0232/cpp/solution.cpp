class Queue {
private:
    stack<int> stk1, stk2;
    void trans() {
        while (!stk1.empty()) {
            int tmp = stk1.top();
            stk1.pop();
            stk2.push(tmp);
        }
    }
public:
    // Push element x to the back of queue.
    void push(int x) {
        stk1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (stk2.empty()) {
            trans();
        }
        stk2.pop();
    }

    // Get the front element.
    int peek(void) {
        if (stk2.empty()) {
            trans();
        }
        return stk2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk1.empty() && stk2.empty();
    }
};

