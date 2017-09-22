package main

func maxProduct(nums []int) (ans int) {
	if len(nums) < 1 {
		return 0
	}
	ans = nums[0]
	max, min := nums[0], nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i] < 0 {
			max, min = min, max
		}
		max2, min2 := max*nums[i], min*nums[i]
		max = nums[i]
		if max < max2 {
			max = max2
		}
		min = nums[i]
		if min > min2 {
			min = min2
		}
		if ans < max {
			ans = max
		}
	}
	return ans
}
