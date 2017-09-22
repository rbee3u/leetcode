#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(0), *prev, *curr;
        while (head) {
            prev = &dummy; curr = dummy.next;
            while (curr && curr->val < head->val) {
                prev = curr;
                curr = curr->next;
            }
            curr = head;
            head = head->next;
            curr->next = prev->next;
            prev->next = curr;
        }
        return dummy.next;
    }
};
