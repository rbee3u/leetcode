#include <iostream>
#include <vector>
#include <map>
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
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        reports.clear();
        if (root) {
            dfs(root, 0, 0);
        }
        vector<vector<int>> results;
        for (auto &report : reports) {
            vector<int> result;
            for (auto &elems : report.second) {
                sort(elems.second.begin(), elems.second.end());
                for (auto elem : elems.second) {
                    result.push_back(elem);
                }
            }
            results.push_back(result);
        }
        return results;
    }

private:
    map<int, map<int, vector<int>>> reports;
    void dfs(TreeNode *curr, int x, int y) {
        reports[x][y].push_back(curr->val);
        if (curr->left) {
            dfs(curr->left, x - 1, y + 1);
        }
        if (curr->right) {
            dfs(curr->right, x + 1, y + 1);
        }
    }
};
