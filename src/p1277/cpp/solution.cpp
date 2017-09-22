class Solution {
public:
    int countSquares(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size(), result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != 0 && j != 0 && mat[i][j] != 0) {
                    int l = min(mat[i][j - 1], mat[i - 1][j]);
                    mat[i][j] = min(mat[i - 1][j - 1], l) + 1;
                }
                result += mat[i][j];
            }
        }
        return result;
    }
};
