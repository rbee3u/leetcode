class Solution {
public:
    static const int MODULO = 1000000007;

    vector<int> pathsWithMaxScore(vector<string> &board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> score(n, vector<int>(m, 0));
        vector<vector<int>> paths(n, vector<int>(m, 0));
        board[0][0] = '0';
        paths[n - 1][m - 1] = 1;

        auto update = [&](int i, int j, int s, int p) {
            if (i < 0 || j < 0 || board[i][j] == 'X') {
                return;
            }
            s += board[i][j] - '0';
            if (score[i][j] < s) {
                score[i][j] = s;
                paths[i][j] = p;
            } else if (score[i][j] == s) {
                paths[i][j] = (paths[i][j] + p) % MODULO;
            }
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (paths[i][j] > 0) {
                    update(i - 1, j, score[i][j], paths[i][j]);
                    update(i, j - 1, score[i][j], paths[i][j]);
                    update(i - 1, j - 1, score[i][j], paths[i][j]);
                }
            }
        }

        return {score[0][0], paths[0][0]};
    }
};
