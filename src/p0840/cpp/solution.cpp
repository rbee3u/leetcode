#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>> &grid) {
        int result = 0;
        auto n = grid.size(), m = grid[0].size();
        for (int i = 0; i + 2 < n; i++) {
            for (int j = 0; j + 2 < m; j++) {
                if (isMagic(grid, i, j)) result++;
            }
        }
        return result;
    }

private:
    bool isMagic(vector<vector<int>> &grid, int i, int j) {
        int visited = 0;
        for (int di = 0; di < 3; di++) {
            for (int dj = 0; dj < 3; dj++) {
                int v = grid[i + di][j + dj];
                if (v <= 0 || v > 9 || (visited >> v & 1)) {
                    return false;
                } else {
                    visited |= 1 << v;
                }
            }
        }

        return grid[i + 0][j + 0] + grid[i + 0][j + 1] + grid[i + 0][j + 2] == 15
            && grid[i + 1][j + 0] + grid[i + 1][j + 1] + grid[i + 1][j + 2] == 15
            && grid[i + 2][j + 0] + grid[i + 2][j + 1] + grid[i + 2][j + 2] == 15
            && grid[i + 0][j + 0] + grid[i + 1][j + 0] + grid[i + 2][j + 0] == 15
            && grid[i + 0][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] == 15
            && grid[i + 0][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] == 15
            && grid[i + 0][j + 0] + grid[i + 1][j + 1] + grid[i + 2][j + 2] == 15
            && grid[i + 0][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j + 0] == 15;
    }
};
