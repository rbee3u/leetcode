class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &mat) {
        int result = INT_MAX;
        int n = int(mat.size()), m = int(mat[0].size());
        for (int i = 1; i < n; i++) {
            int firstVal = INT_MAX, secondVal = INT_MAX;
            int firstIdx = -1;
            for (int j = 0; j < m; j++) {
                if (firstVal > mat[i - 1][j]) {
                    secondVal = firstVal;
                    firstVal = mat[i - 1][j];
                    firstIdx = j;
                } else if (secondVal > mat[i - 1][j]) {
                    secondVal = mat[i - 1][j];
                }
            }
            for (int j = 0; j < m; j++) {
                if (j != firstIdx) {
                    mat[i][j] += firstVal;
                } else {
                    mat[i][j] += secondVal;
                }
                if (i == n - 1) {
                    result = min(result, mat[i][j]);
                }
            }
        }
        return result;
    }
};
