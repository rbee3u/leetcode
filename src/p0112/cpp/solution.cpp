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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {return false;}
        return myPathSum(root, sum, 0);
    }
private:
    bool myPathSum(TreeNode* root, int sum, int acc) {
        if (!root->left && !root->right) {
            return sum == acc + root->val;
        }
        if (!root->left) {
            return myPathSum(root->right, sum, acc+root->val);
        }
        if (!root->right) {
            return myPathSum(root->left, sum, acc+root->val);
        }
        return myPathSum(root->left, sum, acc+root->val)
            || myPathSum(root->right, sum, acc+root->val);
    }
};
