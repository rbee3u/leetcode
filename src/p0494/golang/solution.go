package main

import (
	"fmt"
)

func main() {
	fmt.Println(findTargetSumWays([]int{1,1,1,1,1}, 3))
}

func findTargetSumWays(nums []int, S int) (ans int) {
	n := len(nums)
	p := n / 2
	leftFreq := calcFreq(nums[:p])
	rightFreq := calcFreq(nums[p:])
	for leftK, leftV := range leftFreq {
		ans += leftV * rightFreq[S - leftK]
	}
	return ans
}

func calcFreq(nums []int) map[int]int {
	curr := make(map[int]int)
	curr[0] = 1
	for _, num := range nums {
		prev := curr
		curr = make(map[int]int)
		for k, v := range prev {
			curr[k - num] = curr[k - num] + v
			curr[k + num] = curr[k + num] + v
		}
	}
	return curr
}
