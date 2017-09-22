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
    int rob(TreeNode* root) {
        if (!root) return 0;
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
    }
private:
    pair<int, int> dfs(TreeNode* root) {
        pair<int, int> ret, lhs, rhs;
        if (root->left) {
            lhs = dfs(root->left);
        } else {
            lhs = make_pair(0, 0);
        }
        if (root->right) {
            rhs = dfs(root->right);
        } else {
            rhs = make_pair(0, 0);
        }
        ret.first = root->val + lhs.second + rhs.second;
        ret.second = max(lhs.first, lhs.second)
                    + max(rhs.first, rhs.second);
        return ret;
    }
};
