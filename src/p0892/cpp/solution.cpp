#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int surfaceArea(vector<vector<int>> &grid) {
        n = int(grid.size());
        m = int(grid[0].size());
        int result = 0, shared = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int h = grid[i][j];
                if (h <= 0) continue;
                result += 4 * h + 2;
                shared += near(grid, h, i + 1, j);
                shared += near(grid, h, i - 1, j);
                shared += near(grid, h, i, j + 1);
                shared += near(grid, h, i, j - 1);
            }
        }
        return result - shared / 2;
    }

private:
    int n, m;
    int near(vector<vector<int>> &grid, int h, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m) return 0;
        return 2 * min(h, grid[i][j]);
    }
};
