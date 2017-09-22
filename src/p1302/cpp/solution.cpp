class Solution {
public:
    int deepestLeavesSum(TreeNode *root) {
        if (!root) return 0;
        int result = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            result = 0;
            for (size_t i = q.size(); i > 0; i--) {
                auto curr = q.front();
                q.pop();
                result += curr->val;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return result;
    }
};
