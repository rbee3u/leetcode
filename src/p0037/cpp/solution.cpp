class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        pre_process(board); dfs(board, 0);
    }
private:
    typedef vector<vector<char>> Table;
    const static int THREE; const static int NINE;
    vector<int> ecellpos; int ecellnum, is_found;
    vector<int> vmask_row, vmask_col, vmask_blk;
    void pre_process(Table &board) {
        vmask_row.resize(NINE, 0);
        vmask_col.resize(NINE, 0);
        vmask_blk.resize(NINE, 0);
        for (int row = 0; row < NINE; ++row) {
            for (int col = 0; col < NINE; ++col) {
                char c = board[row][col];
                if (c < '1' || '9' < c) {
                    ecellpos.push_back(row*NINE+col);
                } else {
                    int blk=row/THREE*THREE+col/THREE;
                    do_vmask(row, col, blk, c - '1');
                }
            }
        }
        ecellnum = ecellpos.size(); is_found = 0;
    }
    void dfs(Table &board, int depth) {
        if (is_found || depth==ecellnum) {
            is_found = 1; return;
        }
        int pos = ecellpos[ depth ];
        int row = pos/NINE, col = pos%NINE;
        int blk = row/THREE*THREE+col/THREE;
        for (char c='1'; c <= '9'; ++c) {
            int val = c - '1'; char e = '.';
            if (!is_valid(row, col, blk, val)) continue;
            board[row][col]=c;do_vmask(row,col,blk,val);
            dfs(board, depth+1); if (is_found) return;
            board[row][col]=e;un_vmask(row,col,blk,val);
        }
    }
    bool is_valid(int row, int col, int blk, int val) {
        return !(vmask_row[val] & (1 << row))
            && !(vmask_col[val] & (1 << col))
            && !(vmask_blk[val] & (1 << blk));
    }
    void do_vmask(int row, int col, int blk, int val) {
        vmask_row[val] |= (1 << row);
        vmask_col[val] |= (1 << col);
        vmask_blk[val] |= (1 << blk);
    }
    void un_vmask(int row, int col, int blk, int val) {
        vmask_row[val] &= ~(1 << row);
        vmask_col[val] &= ~(1 << col);
        vmask_blk[val] &= ~(1 << blk);
    }
};
const int Solution::THREE = 3;
const int Solution::NINE =  9;
