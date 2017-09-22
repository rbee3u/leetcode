#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestIsland(vector<vector<int>> &grid) {
        n = static_cast<int>(grid.size());
        if (n == 0) { return 0; }
        m = static_cast<int>(grid[0].size());
        color = 1;
        stats = {0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bfs(grid, i, j);
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    result = max(result, stats[grid[i][j]]);
                } else {
                    int temp = 1;
                    for (auto dir : dirs) {
                        auto ni = i + dir[0], nj = j + dir[1];
                        if (0 <= ni && ni < n && 0 <= nj && nj < m &&
                            grid[ni][nj] > 1 && stats[grid[ni][nj]] > 0) {
                            temp += stats[grid[ni][nj]];
                            stats[grid[ni][nj]] *= -1;
                        }
                    }
                    for (auto dir : dirs) {
                        auto ni = i + dir[0], nj = j + dir[1];
                        if (0 <= ni && ni < n && 0 <= nj && nj < m &&
                            grid[ni][nj] > 1 && stats[grid[ni][nj]] < 0) {
                            stats[grid[ni][nj]] *= -1;
                        }
                    }
                    result = max(result, temp);
                }
            }
        }
        return result;
    }

private:
    int n, m, color, count;
    vector<int> stats;
    static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void bfs(vector<vector<int>> &grid, int x, int y) {
        if (!check(grid, x, y)) { return; }
        grid[x][y] = ++color;
        queue<tuple<int, int>> q;
        q.push({x, y});
        count = 1;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (auto dir : dirs) {
                auto ni = i + dir[0], nj = j + dir[1];
                if (check(grid, ni, nj)) {
                    grid[ni][nj] = color;
                    q.push({ni, nj});
                    count++;
                }
            }
        }
        stats.push_back(count);
    }

    bool check(vector<vector<int>> &grid, int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m && grid[x][y] == 1;
    }
};
