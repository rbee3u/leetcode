int str2num(string s) {
    int ret = 0;
    for (int i = 0; i < s.length(); i++)
        ret = ret * 10 + (s[i] - '0');
    return ret;
}

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk; int x, y, z;
        vector<string>:: iterator it;
        for (it = tokens.begin(); it != tokens.end(); it++) {
            switch ((*it)[0]) {
                case '+' :  y = stk.top(); stk.pop();
                            x = stk.top(); stk.pop();
                            z = x + y; stk.push(z); break;
                case '-' :  if ((*it).length() > 1) {
                                stk.push(-str2num((*it).substr(1)));
                                break;
                            }
                            y = stk.top(); stk.pop();
                            x = stk.top(); stk.pop();
                            z = x - y; stk.push(z); break;
                case '*' :  y = stk.top(); stk.pop();
                            x = stk.top(); stk.pop();
                            z = x * y; stk.push(z); break;
                case '/' :  y = stk.top(); stk.pop();
                            x = stk.top(); stk.pop();
                            z = x / y; stk.push(z); break;
                default  :  stk.push(str2num((*it)));
            }
        }
        return stk.top();
    }
};