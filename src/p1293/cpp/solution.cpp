class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, int k) {

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int n = int(grid.size()), m = int(grid[0].size());
        vector<vector<vector<bool>>> seen(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
        queue<tuple<int, int, int, int>> q;
        seen[n - 1][m - 1][k] = true;
        q.emplace(n - 1, m - 1, k, 0);
        while (!q.empty()) {
            auto[x, y, k, step] = q.front();
            q.pop();
            if (x + y <= k) {
                return step + x + y;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nk = k - grid[nx][ny];
                    if (nk >= 0 && !seen[nx][ny][nk]) {
                        seen[nx][ny][nk] = true;
                        q.emplace(nx, ny, nk, step + 1);
                    }
                }
            }
        }
        return -1;
    }
};
