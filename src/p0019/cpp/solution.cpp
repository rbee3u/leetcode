class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode sentinel(0);
        sentinel.next = head;
        auto first = &sentinel;
        for (int i = 0; i < n; i++) {
            first = first->next;
        }
        auto second = &sentinel;
        while (first->next) {
            first = first->next;
            second = second->next;
        }
        auto removeNode = second->next;
        second->next = removeNode->next;
//        delete removeNode;
        return sentinel.next;
    }
};
