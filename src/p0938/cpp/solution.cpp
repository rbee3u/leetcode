class Solution {
public:
    int rangeSumBST(TreeNode *root, int L, int R) {
        if (!root) return 0;
        if (R < root->val) return rangeSumBST(root->left, L, R);
        if (L > root->val) return rangeSumBST(root->right, L, R);
        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};
