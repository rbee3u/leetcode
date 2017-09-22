#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>> &grid) {
        this->grid = grid;
        rows = static_cast<int>(grid.size());
        cols = static_cast<int>(grid[0].size());
        squares = 2;
        for (auto i = 0; i < rows; i++) {
            for (auto j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    beg_i = i;
                    beg_j = j;
                } else if (grid[i][j] == 2) {
                    end_i = i;
                    end_j = j;
                } else if (grid[i][j] == 0) {
                    squares++;
                }
            }
        }
        result = 0;
        visited.clear();
        visited.insert(beg_i * cols + beg_j);
        dfs(beg_i, beg_j, 1);
        visited.erase(beg_i * cols + beg_j);
        return result;
    }

private:
    vector<vector<int>> grid;
    int rows, cols, squares, result;
    int beg_i, beg_j, end_i, end_j;
    unordered_set<int> visited;

    static constexpr int dirs[4][2] = {{1,  0},
                                       {-1, 0},
                                       {0,  1},
                                       {0,  -1}};

    bool check(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            return false;
        }
        if (grid[i][j] == -1) {
            return false;
        }
        if (visited.find(i * cols + j) != visited.end()) {
            return false;
        }
        return true;
    }

    void dfs(int curr_i, int curr_j, int depth) {
        if (curr_i == end_i && curr_j == end_j) {
            if (depth == squares) {
                result = result + 1;
            }
            return;
        }
        for (auto dir : dirs) {
            auto next_i = curr_i + dir[0];
            auto next_j = curr_j + dir[1];
            if (check(next_i, next_j)) {
                visited.insert(next_i * cols + next_j);
                dfs(next_i, next_j, depth + 1);
                visited.erase(next_i * cols + next_j);
            }
        }
    }
};
