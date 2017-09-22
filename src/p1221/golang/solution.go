func balancedStringSplit(s string) int {
	var result, weight int
	for i := 0; i < len(s); i++ {
		if s[i] == 'L' {
			weight--
		} else {
			weight++
		}
		if weight == 0 {
			result++
		}
	}
	return result
}
