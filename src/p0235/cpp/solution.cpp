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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return search(root, p, q);
    }
private:
    TreeNode* search(TreeNode *parent, TreeNode *p, TreeNode *q) {
        if (p->val < parent->val
            && q->val < parent->val) {
                return search(parent->left, p, q);
            }
        if (p->val > parent->val
            && q->val > parent->val) {
                return search(parent->right, p, q);
            }
        return parent;
    }
};
