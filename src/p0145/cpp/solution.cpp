#include <vector>
#include <stack>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode *root) {
        std::vector<int> result;
//        recursiveTraversal(root, result);
        stackTraversal(root, result);
//        morrisTraversal(root, result);
        return result;
    }

private:
    void recursiveTraversal(TreeNode *root, std::vector<int> &result) {
        if (root) {
            recursiveTraversal(root->left, result);
            recursiveTraversal(root->right, result);
            result.push_back(root->val);
        }
    }

    void stackTraversal(TreeNode *root, std::vector<int> &result) {
        std::stack<TreeNode *> stk;
        if (root) {
            stk.push(root);
            stk.push(root);
        }
        while (!stk.empty()) {
            auto curr = stk.top();
            stk.pop();
            if (!stk.empty() && curr == stk.top()) {
                if (curr->right) {
                    stk.push(curr->right);
                    stk.push(curr->right);
                }
                if (curr->left) {
                    stk.push(curr->left);
                    stk.push(curr->left);
                }
            } else {
                result.push_back(curr->val);
            }
        }
    }

    void stackTraversalFake(TreeNode *root, std::vector<int> &result) {
        std::stack<TreeNode *> stk;
        for (auto curr = root; curr || !stk.empty();) {
            if (curr) {
                stk.push(curr);
                result.push_back(curr->val);
                curr = curr->right;
            } else {
                curr = stk.top()->left;
                stk.pop();
            }
        }
        std::reverse(result.begin(), result.end());
    }

    void morrisTraversal(TreeNode *root, std::vector<int> &result) {
        TreeNode dummy(0);
        dummy.left = root;
        for (auto curr = &dummy; curr;) {
            if (!curr->left) {
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
                    prev->right = nullptr;
                    for (auto p = reverse(curr->left); p; p = p->right) {
                        result.push_back(p->val);
                    }
                    reverse(prev);
                    curr = curr->right;
                }
            }
        }
    }

    TreeNode *reverse(TreeNode *head) {
        TreeNode *prev = nullptr, *curr = head, *next;
        while (curr) {
            next = curr->right;
            curr->right = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void morrisTraversalFake(TreeNode *root, std::vector<int> &result) {
        for (auto curr = root; curr;) {
            if (!curr->right) {
                result.push_back(curr->val);
                curr = curr->left;
            } else {
                auto next = curr->right;
                while (next->left && next->left != curr) {
                    next = next->left;
                }
                if (!next->left) {
                    result.push_back(curr->val);
                    next->left = curr;
                    curr = curr->right;
                } else {
                    next->left = nullptr;
                    curr = curr->left;
                }
            }
        }
        std::reverse(result.begin(), result.end());
    }
};

int main() {
    Solution solution;
    solution.postorderTraversal(nullptr);
    return 0;
}