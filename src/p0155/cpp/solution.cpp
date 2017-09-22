class MinStack {
private:
    stack<int> origin;
    stack<int> minimum;
public:
    void push(int x) {
        origin.push(x);
        if (minimum.empty()) {
            minimum.push(x);
        } else {
            int top = minimum.top();
            minimum.push(min(top, x));
        }
    }

    void pop() {
        origin.pop();
        minimum.pop();
    }

    int top() {
        return origin.top();
    }

    int getMin() {
        return minimum.top();
    }
};