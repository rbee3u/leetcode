class Solution {
public:
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> result;
        for (auto p = head; p; p = p->next) {
            result.push_back(p->val);
        }
        stack<size_t> stk;
        for (size_t i = 0; i < result.size(); i++) {
            while (!stk.empty() && result[stk.top()] < result[i]) {
                result[stk.top()] = result[i]; stk.pop();
            }
            stk.push(i);
        }
        while (!stk.empty()) { result[stk.top()] = 0; stk.pop(); }
        return result;
    }
};
