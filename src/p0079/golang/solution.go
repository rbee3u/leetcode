package main

var (
	n, m int
	found bool
)

func exist(board [][]byte, word string) bool {
	n = len(board)
	if n == 0 {
		return false
	}
	m = len(board[0])
	if m == 0 {
		return false
	}
	found = false
	for x := 0; x < n; x++ {
		for y := 0; y < m; y++ {
			board[x][y] += 128
			dfs(board, word, x, y, 0)
			board[x][y] -= 128
			if found {
				return true
			}
		}
	}
	return false
}

func dfs(board [][]byte, word string, x, y, depth int) {
	if found {
		return
	}
	if word[depth] != board[x][y] % 128 {
		return
	}
	if depth + 1 >= len(word) {
		found = true
		return
	}
	dx := []int{-1, 1, 0, 0}
	dy := []int{0, 0, -1, 1}
	for k := 0; k < 4; k++ {
		nx := x + dx[k]
		ny := y + dy[k]
		if nx < 0 || nx >= n {
			continue
		}
		if ny < 0 || ny >= m {
			continue
		}
		if board[nx][ny] > 128 {
			continue
		}
		board[nx][ny] += 128
		dfs(board, word, nx, ny, depth+1)
		board[nx][ny] -=128
	}
}
