class Solution {
public:
    int getDecimalValue(ListNode *head) {
        int result = 0;
        for (auto p = head; p; p = p->next) {
            result = result * 2 + p->val;
        }
        return result;
    }
};
