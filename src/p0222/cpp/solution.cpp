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
private:
    int hleft(TreeNode *p) {
        int ret = 1;
        for (; p; ret*=2) {
            p = p->left;
        }
        return ret;
    }
    int hright(TreeNode *p) {
        int ret = 1;
        for (; p; ret*=2) {
            p = p->right;
        }
        return ret;
    }
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        if (hleft(root->left) == hright(root->left)) {
            return hleft(root->left) + countNodes(root->right);
        } else {
            return countNodes(root->left) + hleft(root->right);
        }
    }
};
