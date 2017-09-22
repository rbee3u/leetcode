package main

func maximalRectangle(matrix [][]byte) (ans int) {
	n := len(matrix)
	if n == 0 {
		return 0
	}
	m := len(matrix[0])
	if m == 0 {
		return 0
	}
	heights := make([]int, m)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if matrix[i][j] == '0' {
				heights[j] = 0
			} else {
				heights[j]++
			}
		}
		area := largestRectangleArea(heights)
		if ans < area {
			ans = area
		}
	}
	return ans
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
