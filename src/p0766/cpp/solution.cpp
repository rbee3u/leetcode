#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>> &mtx) {
        auto n = mtx.size(), m = mtx[0].size();
        size_t i, j;
        for (i = 0, j = 0; i < n; i++) {
            if (!isSame(mtx, n, m, i, j)) return false;
        }
        for (i = 0, j = 0; j < m; j++) {
            if (!isSame(mtx, n, m, i, j)) return false;
        }
        return true;
    }

private:
    bool isSame(vector<vector<int>> &mtx, size_t n, size_t m, size_t i, size_t j) {
        for (int value = mtx[i][j]; i < n && j < m;) {
            if (mtx[i++][j++] != value) return false;
        }
        return true;
    }
};
