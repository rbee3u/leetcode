func runningSum(nums []int) []int {
	sums, sum := make([]int, len(nums)), 0
	for i, num := range nums {
		sum += num
		sums[i] = sum
	}
	return sums
}
