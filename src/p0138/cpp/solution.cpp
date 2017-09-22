/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL; for (auto *ptr=head; ptr; ) {
            auto tmp = new RandomListNode(ptr->label);
            tmp->next=ptr->next; ptr->next=tmp; ptr=tmp->next;
        }
        for (auto ptr=head; ptr; ptr = ptr->next->next) {
            if (ptr->next->random = ptr->random)
                ptr->next->random = ptr->random->next;
        }
        RandomListNode *copy=head->next, *ptr=head, *tmp;
        for (;tmp=ptr->next;) {ptr->next=tmp->next; ptr=tmp;}
        return copy;
    }
};
