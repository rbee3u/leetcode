class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        auto fast = head, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
