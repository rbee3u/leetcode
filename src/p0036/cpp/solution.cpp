class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> row(9, false);
        vector<bool> col(9, false);
        vector<bool> blk(9, false);
        if (board.size() != 9) return false;
        for (int i=0; i < 9; ++i) {
            if (board[i].size() != 9) return false;
            if (!isValidSquare(board, i, i+1, 0, 9))
                return false;
        }
        for (int j=0; j < 9; ++j) {
            if (!isValidSquare(board, 0, 9, j, j+1))
                return false;
        }
        for (int i=0; i < 9; i +=3) {
            for (int j=0; j < 9; j += 3) {
                if (!isValidSquare(board, i, i+3, j, j+3))
                    return false;
            }
        }
        return true;
    }
private:
    bool isValidSquare(vector<vector<char>>& board
        , int ib, int ie, int jb, int je) {
        bool vst[9] = {false};
        for (int i=ib; i < ie; ++i) {
            for (int j=jb; j < je; ++j) {
                char curr = board[i][j];
                if ('1' <= curr && curr <= '9') {
                    int iurr = curr - '1';
                    if (vst[iurr]) return false;
                    vst[iurr] = true;
                }
            }
        }
        return true;
    }
};
