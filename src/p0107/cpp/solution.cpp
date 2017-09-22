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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        myDfs(root, 0, ret);
        reverse(ret.begin(), ret.end());
        return ret;
    }
private:
    void myDfs(TreeNode* root, int depth, vector<vector<int>>& ret) {
        if (!root) return; if (ret.size() <= depth) {
            ret.push_back(vector<int>());
        }
        ret[depth].push_back(root->val);
        myDfs(root->left, depth+1, ret);
        myDfs(root->right, depth+1, ret);
    }
};
