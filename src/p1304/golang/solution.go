func sumZero(n int) (result []int) {
	if n%2 != 0 {
		result = append(result, 0)
		n--
	}
	for n > 0 {
		result = append(result, n, -n)
		n -= 2
	}
	return result
}
