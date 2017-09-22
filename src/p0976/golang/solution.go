package main

import (
	"sort"
)

func largestPerimeter(A []int) int {
	sort.Slice(A, func(i int, j int) bool {
		return A[i] > A[j]
	})
	for i := 0; i + 2 < len(A); i++ {
		if A[i] - A[i+1] < A[i+2] {
			return A[i] + A[i+1] + A[i+2]
		}
	}
	return 0
}
