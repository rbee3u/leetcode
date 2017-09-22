class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        ListNode *ptr=head, *tmp=head->next;
        for (; tmp && tmp->next; ) {
            ptr = ptr->next; tmp = tmp->next->next;
        }
        ListNode *frnt=ptr->next; ptr->next = NULL;
        ptr = frnt->next; frnt->next = NULL;
        for (; ptr; frnt = ptr, ptr = tmp) {
            tmp = ptr->next; ptr->next = frnt;
        }
        for (ptr = head; frnt; ) {
            tmp = frnt->next; frnt->next = ptr->next;
            ptr->next=frnt; ptr=frnt->next; frnt=tmp;
        }
    }
};
