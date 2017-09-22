#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next) { return head; }
        ListNode *p = head, *q = head->next, *t;
        while (q && q->next) {
            t = q->next;
            q = q->next = t->next;
            t->next = p->next;
            p = p->next = t;
        }
        return head;
    }
};
