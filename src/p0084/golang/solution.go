package main

import (
	"fmt"
)

func main() {
	fmt.Println(largestRectangleArea([]int{0, 9}))
}

func largestRectangleArea(heights []int) (ans int) {
	heights = append(heights, 0)
	n := len(heights)
	indexes := make([]int, n + 1)
	elements := make([]int, n+1)
	top := 0
	indexes[0], elements[0], top = -1, 0, 0
	for i, r := range heights {
		for r < elements[top] {
			h := elements[top]
			top--
			area := (i - indexes[top] - 1) * h
			if ans < area {
				ans = area
			}
		}
		if r > elements[top] {
			top++
			indexes[top] = i
			elements[top] = r
		} else {
			indexes[top] = i
		}
	}
	return ans
}
