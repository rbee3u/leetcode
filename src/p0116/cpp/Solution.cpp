/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *head=root, *temp;
        while (head && head->left) {
            temp = head; while (temp) {
                temp->left->next = temp->right;
                if (temp->next) {
                    temp->right->next = temp->next->left;
                }
                temp = temp->next;
            }
            head = head->left;
        }
    }
};
