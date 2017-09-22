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
    std::vector<int> preorderTraversal(TreeNode *root) {
        std::vector<int> result;
//        recursiveTraversal(root, result);
//        stackTraversal(root, result);
        morrisTraversal(root, result);
        return result;
    }

private:
    void recursiveTraversal(TreeNode *root, std::vector<int> &result) {
        if (root) {
            result.push_back(root->val);
            recursiveTraversal(root->left, result);
            recursiveTraversal(root->right, result);
        }
    }

    void stackTraversal(TreeNode *root, std::vector<int> &result) {
        std::stack<TreeNode *> stk;
        for (auto curr = root; curr || !stk.empty();) {
            if (curr) {
                stk.push(curr);
                result.push_back(curr->val);
                curr = curr->left;
            } else {
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
                    result.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
    }
};

int main() {
    Solution solution;
    solution.preorderTraversal(nullptr);
    return 0;
}