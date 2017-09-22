package main

func minPathSum(grid [][]int) int {
	n := len(grid)
	if n == 0 {
		return 0
	}
	m := len(grid[0])
	if m == 0 {
		return 0
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if i == 0 && j == 0 {
				continue
			}
			if i == 0 && j > 0 {
				grid[i][j] = grid[i][j-1] + grid[i][j]
				continue
			}
			if i > 0 && j == 0 {
				grid[i][j] = grid[i-1][j] + grid[i][j]
				continue
			}
			grid[i][j] += min(grid[i-1][j], grid[i][j-1])
		}
	}
	return grid[n-1][m-1]
}

func min(x int, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}
