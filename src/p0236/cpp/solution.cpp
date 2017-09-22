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
    	TreeNode *ret = NULL, *tp, *tq;
        stack<TreeNode*> sp, sq;
        findPath(root, p, sp);
        findPath(root, q, sq);
        while (!sp.empty() && !sq.empty()) {
        	tp = sp.top();
        	tq = sq.top();
        	if (tp != tq) {
        		break;
        	}
        	sp.pop();
        	sq.pop();
        	ret = tp;
        }
        return ret;
    }
private:
	bool flag;
	void findPath(TreeNode *parent, TreeNode *x, stack<TreeNode*> &stk) {
		if (!parent) {
			return;
		}
		flag = (parent == x);
		if (flag) {
			stk.push(parent);
			return;
		}
		findPath(parent->left, x, stk);
		if (flag) {
			stk.push(parent);
			return;
		}
		findPath(parent->right, x, stk);
		if (flag) {
			stk.push(parent);
			return;
		}
	}
};


