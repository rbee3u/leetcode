#include <iostream>
#include <random>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) : head(head) {
        mt = mt19937(rd());
    }

    /** Returns a random node's value. */
    int getRandom() {
        int result = head->val;
        auto curr = head->next;
        int n = 1;
        while (curr) {
            n++;
            if (dist(mt) % n == 0) {
                result = curr->val;
            }
            curr = curr->next;
        }
        return result;
    }

private:
    ListNode *head;
    random_device rd;
    mt19937 mt;
    uniform_int_distribution<> dist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */