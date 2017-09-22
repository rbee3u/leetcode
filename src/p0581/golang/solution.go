package main

import (
	"fmt"
)

func main() {
	fmt.Printf("%d\n", findUnsortedSubarray([]int{2, 1}))
}

func findUnsortedSubarray(nums []int) int {
	if len(nums) <= 1 {
		return 0
	}
	prefixLength := 1
	for i := 1; i < len(nums); i++ {
		if nums[i-1] > nums[i] {
			break
		}
		prefixLength++
	}
	restMinimum := nums[prefixLength - 1]
	for i := prefixLength; i < len(nums); i++ {
		if restMinimum > nums[i] {
			restMinimum = nums[i]
		}
	}
	for prefixLength > 0 && nums[prefixLength - 1] > restMinimum {
		prefixLength--
	}
	suffixLength := 1
	for i := len(nums) - 1; i > 0; i-- {
		if nums[i-1] > nums[i] {
			break
		}
		suffixLength++
	}
	restMaximum := nums[len(nums) - suffixLength]
	for i := len(nums) - suffixLength - 1; i >= 0; i-- {
		if restMaximum < nums[i] {
			restMaximum = nums[i]
		}
	}
	for suffixLength > 0 && nums[len(nums) - suffixLength] < restMaximum {
		suffixLength--
	}
	m := len(nums) - prefixLength - suffixLength
	if m < 0 {
		return 0
	} else {
		return m
	}
}