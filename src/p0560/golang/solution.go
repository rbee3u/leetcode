package main

func subarraySum(nums []int, k int) int {
	dict := make(map[int]int)
	dict[0] = 1
	sum, ans := 0, 0
	for _, num := range nums {
		sum = sum + num
		ans += dict[sum - k]
		dict[sum] = dict[sum] + 1
	}
	return ans
}
