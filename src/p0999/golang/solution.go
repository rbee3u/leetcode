package main

func numRookCaptures(board [][]byte) int {
	for x := 0; x < 8; x++ {
		for y := 0; y < 8; y++ {
			if board[x][y] == 'R' {
				return capture(board, x, y, 0, 1) +
					capture(board, x, y, 0, -1) +
					capture(board, x, y, -1, 0) +
					capture(board, x, y, 1, 0)
			}
		}
	}
	return 0
}

func capture(board [][]byte, x, y, dx, dy int) int {
	for 0 <= x && x < 8 && 0 <= y && y < 8 {
		switch board[x][y] {
		case 'p':
			return 1
		case 'B':
			return 0
		default:
			x, y = x + dx, y + dy
		}
	}
	return 0
}
