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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *curr=head, *next=head->next;
        for (; next; ) {
            if (curr->val == next->val) {
                curr->next = next->next;
                delete next; next = curr->next;
            } else {
                curr = next; next = next->next;
            }
        }
        return head;
    }
};
