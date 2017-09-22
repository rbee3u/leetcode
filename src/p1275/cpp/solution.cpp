class Solution {
public:
    string tictactoe(vector<vector<int>> &moves) {
        string g(9, ' ');
        auto row = [&g](int i, char t) {
            return g[i * 3] == t && g[i * 3 + 1] == t && g[i * 3 + 2] == t;
        };
        auto col = [&g](int j, char t) {
            return g[j] == t && g[3 + j] == t && g[6 + j] == t;
        };
        auto dia = [&g](int d, char t) {
            return g[4] == t && g[7 + d] == t && g[1 - d] == t;
        };
        bool roundA = true;
        for (auto &move : moves) {
            int i = move[0], j = move[1];
            char t = roundA ? 'X' : 'O';
            g[i * 3 + j] = t;
            if (row(i, t) || col(j, t) || dia(1, t) || dia(-1, t)) {
                return roundA ? "A" : "B";
            }
            roundA = !roundA;
        }
        return moves.size() < 9 ? "Pending" : "Draw";
    }
};
