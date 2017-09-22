class Codec {
private:
    string num2str(int num) {
        char buff[11];
        sprintf(buff, "%d", num);
        return buff;
    }
    int str2num(string str) {
        return atoi(str.c_str());
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret, tmp;
        TreeNode dummy(0); dummy.right=root;
        queue<TreeNode*> q; q.push(&dummy);
        while (!q.empty()) {
            TreeNode *ptr = q.front(); q.pop();
            if (ptr) {
                TreeNode *lft = ptr->left;
                TreeNode *rht = ptr->right;
                tmp = "null"; if (lft) {
                    tmp = num2str(lft->val);
                    q.push(lft);
                }
                ret += tmp + "|";
                tmp = "null"; if (rht) {
                    tmp = num2str(rht->val);
                    q.push(rht);
                }
                ret += tmp + "|";
            }
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vec;
        string tmp; for (auto x : data) {
            if (x == '|') {
                vec.push_back(tmp);
                tmp = "";
            } else {
                tmp += x;
            }
        }
        int vsize=vec.size(); TreeNode dummy(0);
        queue<TreeNode*> q; q.push(&dummy);
        for (int i=0; i < vsize; ) {
            TreeNode *ptr = q.front(); q.pop();
            if (ptr) {
                tmp = vec[i++];
                if (tmp != "null") {
                    int val = str2num(tmp);
                    ptr->left = new TreeNode(val);
                    q.push(ptr->left);
                }
                tmp = vec[i++];
                if (tmp != "null") {
                    int val = str2num(tmp);
                    ptr->right = new TreeNode(val);
                    q.push(ptr->right);
                }
            }
        }
        return dummy.right;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
