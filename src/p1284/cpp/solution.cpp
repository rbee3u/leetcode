class Solution {
public:
    int minFlips(vector<vector<int>> &mat) {
        auto n = int(mat.size()), m = int(mat[0].size());
        auto result = INT_MAX;
        for (auto first = 0; first < (1 << m); first++) {
            vector<vector<int>> tmp(mat);
            auto count = 0;
            for (auto j = 0; j < m; j++) {
                if (first & (1 << j)) {
                    flip(tmp, n, m, 0, j);
                    count++;
                }
            }
            for (auto i = 1; i < n; i++) {
                for (auto j = 0; j < m; j++) {
                    if (tmp[i - 1][j]) {
                        flip(tmp, n, m, i, j);
                        count++;
                    }
                }
            }
            auto last = 0;
            for (auto j = 0; j < m; j++) {
                last += tmp[n - 1][j];
            }
            if (last == 0 && result > count) {
                result = count;
            }
        }
        if (result == INT_MAX) {
            return -1;
        }
        return result;
    }

    void flip(vector<vector<int>> &mat, int n, int m, int i, int j) {
        mat[i][j] ^= 1;
        if (i - 1 >= 0) mat[i - 1][j] ^= 1;
        if (i + 1 < n) mat[i + 1][j] ^= 1;
        if (j - 1 >= 0) mat[i][j - 1] ^= 1;
        if (j + 1 < m) mat[i][j + 1] ^= 1;
    }
};
