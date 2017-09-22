func findNumbers(nums []int) (result int) {
	for _, x := range nums {
		length := len(fmt.Sprint(x))
		result += (length + 1) % 2
	}
	return result
}
