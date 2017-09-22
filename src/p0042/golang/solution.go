func trap(height []int) int {
	var water, lbound, rbound int
	left, right := 0, len(height)
	for left < right {
		if lbound < rbound {
			curr := height[left]
			left++
			if lbound < curr {
				lbound = curr
			} else {
				water += lbound - curr
			}
		} else {
			right--
			curr := height[right]
			if rbound < curr {
				rbound = curr
			} else {
				water += rbound - curr
			}
		}
	}
	return water
}
