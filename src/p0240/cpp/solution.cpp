class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = 0;
        if (n) m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0) {
            int tmp = matrix[i][j];
            if (tmp < target) {
                ++i;
            } else
            if (tmp > target) {
                --j;
            } else {
                return true;
            }
        }
        return false;
    }
};
