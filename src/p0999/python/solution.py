from typing import List


class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        for x in range(8):
            for y in range(8):
                if board[x][y] == 'R':
                    return self.cap(board, x, y, 0, 1) + \
                           self.cap(board, x, y, 0, -1) + \
                           self.cap(board, x, y, 1, 0) + \
                           self.cap(board, x, y, -1, 0)

    def cap(self, board, x, y, dx, dy):
        while 0 <= x < 8 and 0 <= y < 8:
            if board[x][y] == 'p':
                return 1
            elif board[x][y] == 'B':
                return 0
            else:
                x, y = x + dx, y + dy
        return 0
