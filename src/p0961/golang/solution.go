package main

func repeatedNTimes(A []int) int {
	for i := 2; i < len(A); i++ {
		if A[i-2] == A[i] || A[i-1] == A[i] {
			return A[i]
		}
	}
	return A[len(A)-1]
}
