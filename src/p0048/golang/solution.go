package main

func rotate(matrix [][]int) {
	n := len(matrix)
	for i := 0; i < n/2; i++ {
		for j := i; j < n-1-i; j++ {
			ci, cj := i, j
			for k := 0; k < 4; k++ {
				pi, pj := prev(ci, cj, n)
				matrix[pi][pj], matrix[ci][cj] = matrix[ci][cj], matrix[pi][pj]
				ci, cj = pi, pj
			}
		}
	}
}

func prev(i int, j int, n int) (ni int, nj int) {
	return n - 1 - j, i
}
