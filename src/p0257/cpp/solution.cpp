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
    vector<string> ret;
    string num2str(int num) {
        char buff[11];
        sprintf(buff, "%d", num);
        return buff;
    }
    void dfs(TreeNode *curr, string path) {
        path += "->" + num2str(curr->val);
        if (!curr->left && !curr->right) {
            ret.push_back(path);
        }
        if (curr->left) {
            dfs(curr->left, path);
        }
        if (curr->right) {
            dfs(curr->right, path);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        ret.clear(); if (!root) return ret;
        string path = num2str(root->val);
        if (!root->left && !root->right) {
            ret.push_back(path);
        }
        if (root->left) {
            dfs(root->left, path);
        }
        if (root->right) {
            dfs(root->right, path);
        }
        return ret;
    }
};
