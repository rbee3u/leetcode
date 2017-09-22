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
    int numComponents(ListNode *head, vector<int> &G) {
        unordered_set<int> s(G.begin(), G.end());
        int result = 0;
        bool prevIsInG = false;
        for (auto curr = head; curr; curr = curr->next) {
            if (s.find(curr->val) != s.end() ) {
                if (!prevIsInG) {
                    result++;
                }
                prevIsInG = true;
            } else {
                prevIsInG = false;
            }
        }
        return result;
    }
};
