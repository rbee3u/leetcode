func convert(s string, numRows int) string {
	if numRows <= 1 {
		return s
	}
	var result []byte
	for k := 0; k < numRows; k++ {
		for x := k; x < len(s); {
			result = append(result, s[x])
			x += 2 * (numRows - 1)
			if 0 < k && k < numRows - 1 {
				y := x - k - k
				if y < len(s) {
					result = append(result, s[y])
				}
			}
		}
	}
	return string(result)
}
