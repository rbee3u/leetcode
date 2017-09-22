class Solution {
public:
    static ListNode *addTwoNumbers(ListNode *a, ListNode *b) {
        ListNode sentinel(0), *tail = &sentinel;
        for (int carry = 0; carry || a || b; carry /= 10) {
            if (a) {
                carry += a->val;
                a = a->next;
            }
            if (b) {
                carry += b->val;
                b = b->next;
            }
            tail = tail->next = new ListNode(carry % 10);
        }
        return sentinel.next;
    }
};
