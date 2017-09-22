#include <iostream>
#include <vector>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *bstFromPreorder(const vector<int> &v) {
        i = 0; return build(v, INT_MAX);
    }

private:
    size_t i;
    TreeNode *build(const vector<int> &v, int bound) {
        if (i < v.size() && v[i] <= bound) {
            auto node = new TreeNode(v[i++]);
            node->left = build(v, node->val);
            node->right = build(v, bound);
            return node;
        }
        return nullptr;
    }
};
