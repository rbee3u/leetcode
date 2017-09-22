class Solution {
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold) {
        int n = int(mat.size()), m = int(mat[0].size()), l = 1;
        vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
        auto area = [&sum](int i, int j, int l) -> int {
            return sum[i - l][j] + sum[i][j - l] - sum[i - l][j - l];
        };
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = area(i, j, 1) + mat[i - 1][j - 1];
                if (i >= l && j >= l && sum[i][j] - area(i, j, l) <= threshold) l++;
            }
        }
        return l - 1;
    }
};
