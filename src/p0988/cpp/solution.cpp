#include <iostream>
#include <vector>
#include <string>
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
    string smallestFromLeaf(TreeNode *root) {
        if (!root) {
            return "";
        }
        auto tail = string(1, root->val + 'a');
        if (!root->left) {
            return smallestFromLeaf(root->right) + tail;
        }
        if (!root->right) {
            return smallestFromLeaf(root->left) + tail;
        }
        return min(smallestFromLeaf(root->left), smallestFromLeaf(root->right)) + tail;
    }
};
