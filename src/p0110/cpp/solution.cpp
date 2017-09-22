/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return myBalanced(root) != -1;
    }
private:
    int myBalanced(TreeNode* root) {
        if (!root) {return 0;}
        int lhs = myBalanced(root->left);
        int rhs = myBalanced(root->right);
        if (lhs < 0 || rhs < 0
            || lhs > rhs + 1
            || rhs > lhs + 1) {
                return -1;
        }
        return 1 + max(lhs, rhs);
    }
};

