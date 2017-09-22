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
	void dfs(TreeNode *parent, int &n, int &ret) {
		if (parent->left) {
			dfs(parent->left, n, ret);
			if (n <= 0) {
				return;
			}
		}
		--n;
		if (n <= 0) {
			ret = parent->val;
			return;
		}
		if (parent->right) {
			dfs(parent->right, n, ret);
		}
	}
public:
    int kthSmallest(TreeNode* root, int k) {
        int ret = 0, n = k;
        dfs(root, n, ret);
        return ret;
    }
};
