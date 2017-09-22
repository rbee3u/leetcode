func romanToInt(s string) int {
	result, prev, curr := 0, 0, 0
	for i := len(s); i > 0; prev = curr {
		i--
		curr = c2n(s[i])
		if curr < prev {
			result -= curr
		} else {
			result += curr
		}
	}
	return result
}

func c2n(c byte) int {
	switch c {
	case 'I':
		return 1
	case 'V':
		return 5
	case 'X':
		return 10
	case 'L':
		return 50
	case 'C':
		return 100
	case 'D':
		return 500
	case 'M':
		return 1000
	default:
		return 0
	}
}
