class Solution {
public:
    bool isValid(const string &s) {
        stack<char> stk;
        for (auto x : s) {
            if (stk.empty()) {
                stk.push(x);
            } else {
                if (isMatch(stk.top(), x)) {
                    stk.pop();
                } else {
                    stk.push(x);
                }
            }
        }
        return stk.empty();
    }

    bool isMatch(char p, char q) {
        return (p == '(' && q == ')') ||
               (p == '{' && q == '}') ||
               (p == '[' && q == ']');
    }
};
