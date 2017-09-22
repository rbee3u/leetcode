package main

import (
	"math"
	"sort"
)

func largestSumAfterKNegations(nums []int, k int) int {
	sort.Ints(nums)
	total, value := 0, math.MaxInt32
	for _, num := range nums {
		if num < 0 && k > 0 {
			num, k = -num, k - 1
		}
		total += num
		if value > num {
			value = num
		}
	}
	return total - (k % 2) * 2 * value
}
