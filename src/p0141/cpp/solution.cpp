/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *slow=head, *fast=head; do {
            fast = fast->next; if (!fast)  break;
            fast = fast->next; slow = slow->next;
        } while (fast && slow!=fast);
        return slow == fast;
    }
};
