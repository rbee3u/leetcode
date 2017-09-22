#include <iostream>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longestUnivaluePath(TreeNode *root) {
        if (!root) return 0;
        int result = 0;
        dfs(root, result);
        return result;
    }

private:
    int dfs(TreeNode *node, int &result) {
        int left = 0;
        if (node->left) {
            int temp = dfs(node->left, result);
            if (node->left->val == node->val) {
                left = temp + 1;
            }
        }
        int right = 0;
        if (node->right) {
            int temp = dfs(node->right, result);
            if (node->right->val == node->val) {
                right = temp + 1;
            }
        }
        result = max(result, left + right);
        return max(left, right);
    }
};
