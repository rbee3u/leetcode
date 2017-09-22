package main

func findDisappearedNumbers(nums []int) (results []int) {
	for _, num := range nums {
		nums[abs(num)-1] = -abs(nums[abs(num)-1])
	}
	for i, num := range nums {
		if num > 0 {
			results = append(results, i+1)
		} else {
			nums[i] = - nums[i]
		}
	}
	return results
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
