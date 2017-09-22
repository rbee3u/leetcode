class Solution {
private:
    int n, m;
private:
    int add_next(int curr, int next) {
        return (curr | (next << 1));
    }
    int get_next(int curr_and_next) {
        return (curr_and_next >> 1);
    }
    int get_curr(int curr_and_next) {
        return (curr_and_next & 1);
    }
    bool valid(int i, int j) {
        return (0 <= i && i < n)
            && (0 <= j && j < m);
    }
    int calc_next(vector<vector<int>>& board, int i, int j) {
        int di[8] = {1,1,1,0,0,-1,-1,-1};
        int dj[8] = {1,0,-1,1,-1,1,0,-1};
        int livesum=0; for (int k=0; k < 8; ++k) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (valid(ni, nj) && get_curr(board[ni][nj])) {
                ++livesum;
            }
        }
        if (livesum < 2 || livesum > 3) {
            return 0;
        } else
        if (livesum == 3) {
            return 1;
        } else {
            return get_curr(board[i][j]);
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size(); m = 0;
        if (n > 0) {
            m = board[0].size();
        }
        for (int i=0; i < n; ++i) {
            for (int j=0; j < m; ++j) {
                int curr = get_curr(board[i][j]);
                int next = calc_next(board, i, j);
                int curr_and_next = add_next(curr, next);
                board[i][j] = curr_and_next;
            }
        }
        for (int i=0; i < n; ++i) {
            for (int j=0; j < m; ++j) {
                board[i][j] = get_next(board[i][j]);
            }
        }
    }
};
