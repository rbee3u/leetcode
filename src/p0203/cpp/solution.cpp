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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode *ptr = head, *tmp;
        while (ptr->next) {
            if (ptr->next->val == val) {
                tmp = ptr->next;
                ptr->next = tmp->next;
                delete tmp;
            } else {
                ptr = ptr->next;
            }
        }
        tmp = head->next;
        if (head->val == val) {
            delete head; return tmp;
        } else {
            return head;
        }
    }
};