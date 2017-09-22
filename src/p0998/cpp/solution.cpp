#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
        TreeNode sentinel(0); sentinel.right = root;
        TreeNode *prev = &sentinel, *curr = root;
        while (curr && curr->val > val) {
            prev = curr; curr = curr->right;
        }
        prev->right = new TreeNode(val);
        prev->right->left = curr;
        return sentinel.right;
    }
};
