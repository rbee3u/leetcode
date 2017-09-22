#include <iostream>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode *root) {
        int counter = 0, prev = 0, result = INT_MAX;
        inOrderTraversal(root, counter, prev, result);
        return result;
    }

private:
    void inOrderTraversal(TreeNode *node, int &counter, int &prev, int &result) {
        if (node) {
            inOrderTraversal(node->left, counter, prev, result);
            if (counter > 0) {
                result = min(result, node->val - prev);
            }
            prev = node->val; counter++;
            inOrderTraversal(node->right, counter, prev, result);
        }
    }
};
