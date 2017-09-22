package main

func pancakeSort(A []int) (ans []int) {
	for end := len(A); end > 0; end-- {
		idx := findMax(A, end)
		reverse(A, idx + 1)
		reverse(A, end)
		ans = append(ans, idx + 1, end)
	}
	return ans
}

func findMax(A []int, end int) (idx int) {
	max := A[0]
	for i := 1; i < end; i++ {
		if max < A[i] {
			max, idx = A[i], i
		}
	}
	return idx
}

func reverse(A []int, end int) {
	i, j := 0, end - 1
	for i < j {
		A[i], A[j] = A[j], A[i]
		i++
		j--
	}
}
