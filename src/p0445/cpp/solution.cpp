#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<ListNode *> s1, s2;
        for (auto p1 = l1; p1; p1 = p1->next) s1.push(p1);
        for (auto p2 = l2; p2; p2 = p2->next) s2.push(p2);
        ListNode dummy(0);
        for (int carry = 0; carry || !s1.empty() || !s2.empty(); carry /= 10) {
            if (!s1.empty()) {
                carry += s1.top()->val; s1.pop();
            }
            if (!s2.empty()) {
                carry += s2.top()->val; s2.pop();
            }
            auto node = new ListNode(carry % 10);
            node->next = dummy.next;
            dummy.next = node;
        }
        return dummy.next;
    }
};