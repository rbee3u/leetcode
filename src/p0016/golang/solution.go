func threeSumClosest(nums []int, target int) int {
	minSum, minDelta := 0, math.MaxInt32
	sort.Ints(nums)
	for i := 0; i < len(nums); i++ {
		for j, k := i+1, len(nums)-1; j < k; {
			sum := nums[i] + nums[j] + nums[k]
			if sum < target {
				j++
			} else if sum > target {
				k--
			} else {
				return sum
			}
			delta := sum - target
			if delta < 0 {
				delta = -delta
			}
			if minDelta > delta {
				minSum, minDelta = sum, delta
			}
		}
	}
	return minSum
}
