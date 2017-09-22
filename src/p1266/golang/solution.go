func abs(x int) int {
	if x >= 0 {
		return x
	}
	return -x
}

func max(x int, y int) int {
	if x >= y {
		return x
	}
	return y
}

func minTimeToVisitAllPoints(points [][]int) (result int) {
	for i := 1; i < len(points); i++ {
		dx := points[i][0] - points[i-1][0]
		dy := points[i][1] - points[i-1][1]
		result += max(abs(dx), abs(dy))
	}
	return result
}
