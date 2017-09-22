struct Iterator {
    stack<TreeNode *> father;
    TreeNode sentinel, *curr;

    Iterator(TreeNode *root) : sentinel(0) {
        sentinel.left = root;
        curr = &sentinel;
        while (curr->left) { moveLeft(); }
    }

    bool HasNext() {
        return curr != &sentinel;
    }

    int Data() {
        return curr->val;
    }

    void Next() {
        if (curr->right) {
            moveRight();
            while (curr->left) { moveLeft(); }
        } else {
            while (curr == father.top()->right) {
                moveParent();
            }
            moveParent();
        }
    }

    void moveLeft() {
        father.push(curr);
        curr = curr->left;
    }

    void moveRight() {
        father.push(curr);
        curr = curr->right;
    }

    void moveParent() {
        curr = father.top();
        father.pop();
    }
};

class Solution {
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> result;
        Iterator i1(root1), i2(root2);
        while (i1.HasNext() && i2.HasNext()) {
            if (i1.Data() < i2.Data()) {
                result.push_back(i1.Data());
                i1.Next();
            } else {
                result.push_back(i2.Data());
                i2.Next();
            }
        }
        while (i1.HasNext()) {
            result.push_back(i1.Data());
            i1.Next();
        }
        while (i2.HasNext()) {
            result.push_back(i2.Data());
            i2.Next();
        }
        return result;
    }
};
