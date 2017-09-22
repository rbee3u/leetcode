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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode foo(0); foo.next = head;
        ListNode *dmmy = &foo, *q, *qq;
        ListNode *pp = dmmy, *p = head;
        for (; ; ) {
            q = p;
            for (int i=1; i<k && q; ) {
                q = q->next; ++i;
            }
            if (!q) break; qq = q->next;
            reverse(p, qq); pp->next = q;
            p->next = qq; pp = p; p = qq;
        }
        return dmmy->next;
    }
private:
    void reverse(ListNode *begin, ListNode *end) {
        if (!begin || begin == end) return;
        ListNode *prev=begin, *curr=prev->next;
        for (; curr != end; ) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr; curr = next;
        }
    }
};
