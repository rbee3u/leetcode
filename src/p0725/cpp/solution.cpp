#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        vector<ListNode *> result;
        int n = 0;
        for (auto curr = head; curr; curr = curr->next) { n++; }
        int q = n / k, r = n % k;
        for (int i = 0; i < k; i++) {
            ListNode *prev = nullptr, *curr = head;
            for (int j = 0; j < q + (i < r); j++) {
                prev = curr;
                curr = curr->next;
            }
            if (prev) {
                prev->next = nullptr;
            }
            result.push_back(head);
            head = curr;
        }
        return result;
    }
};
