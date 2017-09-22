#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct State {
        int x, y, step;

        State(int ax, int ay, int astep) : x(ax), y(ay), step(astep) {}
    };

    int orangesRotting(vector<vector<int>> &grid) {
        int n = static_cast<int>(grid.size());
        int m = static_cast<int>(grid[0].size());
        int good = 0;
        queue<State> q;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                switch (grid[x][y]) {
                case 1: good++; break;
                case 2: q.emplace(x, y, 0); break;
                }
            }
        }
        int result = 0;
        while (!q.empty()) {
            auto s = q.front(); q.pop();
            result = s.step;
            for (auto d : ds) {
                int nx = s.x + d[0], ny = s.y + d[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1) {
                    continue;
                }
                grid[nx][ny] = 2;
                q.emplace(nx, ny, s.step + 1);
                good--;
            }
        }
        if (good != 0) {
            return -1;
        } else {
            return result;
        }
    }

private:
    static constexpr int ds[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
