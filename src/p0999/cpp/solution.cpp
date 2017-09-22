#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>> &board) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (board[x][y] == 'R') {
                    return cap(board, x, y, 0, 1) + cap(board, x, y, 0, -1)
                         + cap(board, x, y, 1, 0) + cap(board, x, y, -1, 0);
                }
            }
        }
        return 0;
    }

private:
    int cap(vector<vector<char>> &board, int x, int y, int dx, int dy) {
        while (0 <= x && x < 8 && 0 <= y && y < 8) {
            switch (board[x][y]) {
                case 'p': return 1;
                case 'B': return 0;
                default: x += dx; y += dy;
            }
        }
        return 0;
    }
};