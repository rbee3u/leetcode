class Solution {
public:
    int countPairs(TreeNode *root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }

    vector<int> dfs(TreeNode *node, int distance, int &result) {
        if (!node) return {};
        if (!node->left && !node->right) return {1};
        auto leftHeights = dfs(node->left, distance, result);
        auto rightHeights = dfs(node->right, distance, result);
        for (int leftHeight : leftHeights)
            for (int rightHeight : rightHeights)
                if (leftHeight + rightHeight <= distance) result++;

        vector<int> allHeights;
        for (int leftHeight : leftHeights)
            if (leftHeight + 1 <= distance)
                allHeights.push_back(leftHeight + 1);
        for (int rightHeight : rightHeights)
            if (rightHeight + 1 <= distance)
                allHeights.push_back(rightHeight + 1);
        return allHeights;
    }
};
