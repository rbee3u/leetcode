/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size(); if (n <= 0) return NULL;
        vector<TreeNode*> array(n+1, NULL);
        for (int i=1; i <= n; ++i) {
            array[i] = new TreeNode(0);
        }
        int cnt=0; dfsVisit(cnt, 1, n, array, nums);
        return array[1];
    }
private:
    void dfsVisit(int &cnt, int idx, int n, vector<TreeNode*> &array, vector<int>& nums) {
        if (idx*2 <= n) {
            array[idx]->left = array[idx*2];
            dfsVisit(cnt, idx*2, n, array, nums);
        }
        array[idx]->val = nums[cnt]; ++cnt;
        if (idx*2+1 <= n) {
            array[idx]->right = array[idx*2+1];
            dfsVisit(cnt, idx*2+1, n, array, nums);
        }
    }
};
