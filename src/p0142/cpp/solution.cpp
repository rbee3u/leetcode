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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *slow=head, *fast=head; do {
            fast = fast->next; if (!fast)  break;
            fast = fast->next; slow = slow->next;
        } while (fast && slow!=fast);
        if (!fast) return NULL;
        fast = head; while (slow != fast) {
            fast = fast->next; slow = slow->next;
        }
        return fast;
    }
};
