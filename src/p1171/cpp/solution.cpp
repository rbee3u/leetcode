class Solution {
public:
    ListNode *removeZeroSumSublists(ListNode *head) {
        ListNode sentinel(0);
        sentinel.next = head;
        unordered_map<int, ListNode *> last;
        int total = 0;
        for (auto p = &sentinel; p; p = p->next) {
            total += p->val;
            last[total] = p;
        }
        total = 0;
        for (auto p = &sentinel; p; p = p->next) {
            total += p->val;
            p->next = last[total]->next;
        }
        return sentinel.next;
    }
};
