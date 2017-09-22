class Stack {
private:
    queue<int> q1, q2;
public:
    // Push element x onto stack.
    void push(int x) {
        if (!q2.empty()) {
            q2.push(x);
        }
        else {
            q1.push(x);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> t;
        if (!q2.empty()) {
            t = q1; q1 = q2; q2 = t;
        }
        int x;
        for (; !q1.empty(); ) {
            x = q1.front();
            q1.pop();
            if (!q1.empty()) {
                q2.push(x);
            }
        }
    }

    // Get the top element.
    int top() {
        queue<int> t;
        if (!q2.empty()) {
            t = q1; q1 = q2; q2 = t;
        }
        int x;
        for (; !q1.empty(); ) {
            x = q1.front();
            q1.pop();
            q2.push(x);
        }
        return x;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};
