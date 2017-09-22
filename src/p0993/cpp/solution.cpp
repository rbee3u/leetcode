#include <iostream>
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
    bool isCousins(TreeNode *root, int x, int y) {
        int dx = 0, dy = 0;
        TreeNode *fx = nullptr, *fy = nullptr;
        findDepth(root, x, 0, dx, fx);
        findDepth(root, y, 0, dy, fy);
        return dx == dy && fx != fy;
    }

private:
    void findDepth(TreeNode *node, int k, int depth, int &d, TreeNode *&f) {
        if (!node || d > 0) {
            return;
        }
        if (node->val == k) {
            d = depth;
            return;
        }
        f = node;
        if (node->left) {
            findDepth(node->left, k, depth + 1, d, f);
        }
        if (node->right) {
            findDepth(node->right, k, depth + 1, d, f);
        }
    }
};
