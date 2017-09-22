#include <iostream>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode dummy(0);
        dummy.next = head;
        int n = 0;
        for (; head; head = head->next) { n++; }
        ListNode *p, *q, *r;
        for (int step = 1; step < n; step *= 2) {
            p = &dummy;
            for (;;) {
                q = skip(p, step);
                if (!q->next) break;
                r = skip(q, step);
                p = merge(p, q, r);
            }
        }
        return dummy.next;
    }

private:
    ListNode *merge(ListNode *p, ListNode *q, ListNode *r) {
        for (;;) {
            if (p->next->val <= q->next->val) {
                p = p->next;
                if (p == q) { return r; }
            } else {
                auto t = q->next;
                q->next = t->next;
                t->next = p->next;
                p = p->next = t;
                if (t == r) { return q; }
            }
        }
    }

    ListNode *skip(ListNode *p, int k) {
        for (; p && p->next && k--; p = p->next);
        return p;
    }
};
