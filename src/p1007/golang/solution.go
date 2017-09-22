package main

func minDominoRotations(A []int, B []int) int {
	n := len(A)
	for _, choose := range [2]int{A[0], B[0]} {
		i, a, b := 0, 0, 0
		for ; i < n && (A[i] == choose || B[i] == choose); i++ {
			if A[i] != choose {
				a++
			}
			if B[i] != choose {
				b++
			}
			if i + 1 == n {
				if a < b {
					return a
				} else {
					return b
				}
			}
		}
	}
	return -1
}
