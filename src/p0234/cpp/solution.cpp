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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        if (!head->next) return true;
        ListNode *list = NULL;
        split(head, list);
        reverse(list);
        bool ret = compare(head, list);
        reverse(list);
        append(head, list);
        return ret;
    }
private:
    int length(ListNode *head) {
        int ret = 0;
        ListNode *ptr = head;
        for (; ptr; ptr=ptr->next) {
            ++ret;
        }
        return ret;
    }
    void split(ListNode *&head, ListNode *&list) {
        int len = length(head);
        ListNode *ptr = head;
        for (int i = 2; i*2 <= (len+1); ++i) {
            ptr = ptr->next;
        }
        list = ptr->next;
        ptr->next = NULL;
    }
    void reverse(ListNode *&head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next;
        for (; curr; ) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    bool compare(ListNode *head, ListNode *list) {
        ListNode *p1 = head;
        ListNode *p2 = list;
        for (; p1 && p2; ) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
    void append(ListNode *&head, ListNode *&list) {
        ListNode *ptr = head;
        for (; ptr->next; ) {
            ptr = ptr->next;
        }
        ptr->next = list;
    }

};


