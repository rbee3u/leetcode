#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
        auto *root = new TreeNode(pre[0]);
        stack<TreeNode *> stk;
        stk.push(root);
        for (auto i = 1, j = 0; i < pre.size(); i++) {
            auto next = new TreeNode(pre[i]);
            if (!stk.top()->left) {
                stk.top()->left = next;
            } else {
                stk.top()->right = next;
            }
            stk.push(next);
            while (!stk.empty() && stk.top()->val == post[j]) {
                j++;
                stk.pop();
            }
        }
        return root;
    }
};