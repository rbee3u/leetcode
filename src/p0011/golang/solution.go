func maxArea(hs []int) int {
	result, i, j := 0, 0, len(hs)
	for i+1 < j {
		if hs[i] < hs[j-1] {
			if result < (j-1-i)*hs[i] {
				result = (j - 1 - i) * hs[i]
			}
			i++
		} else {
			if result < (j-1-i)*hs[j-1] {
				result = (j - 1 - i) * hs[j-1]
			}
			j--
		}
	}
	return result
}
