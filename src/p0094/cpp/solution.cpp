#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> result;
//        recursiveTraversal(root, result);
//        stackTraversal(root, result);
        morrisTraversal(root, result);
        return result;
    }

private:
    void recursiveTraversal(TreeNode *root, std::vector<int> &result) {
        if (root) {
            recursiveTraversal(root->left, result);
            result.push_back(root->val);
            recursiveTraversal(root->right, result);
        }
    }

    void stackTraversal(TreeNode *root, std::vector<int> &result) {
        std::stack<TreeNode *> stk;
        for (auto curr = root; curr || !stk.empty();) {
            if (curr) {
                stk.push(curr);
                curr = curr->left;
            } else {
                result.push_back(stk.top()->val);
                curr = stk.top()->right;
                stk.pop();
            }
        }
    }

    void morrisTraversal(TreeNode *root, std::vector<int> &result) {
        for (auto curr = root; curr;) {
            if (!curr->left) {
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                auto prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    result.push_back(curr->val);
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
    }
};

int main() {
    Solution solution;
    solution.inorderTraversal(nullptr);
    return 0;
}