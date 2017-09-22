func myAtoi(s string) (y int) {

	i := 0

	for i < len(s) && s[i] == ' ' {
		i++
	}
	if i >= len(s) {
		return y
	}

	sign := 1
	if s[i] == '-' {
		sign = -1
		i++
	} else if s[i] == '+' {
		i++
	}

	for i < len(s) && '0' <= s[i] && s[i] <= '9' {
		b := sign * int(s[i]-'0')
		if sign > 0 && (y > math.MaxInt32/10 || (y == math.MaxInt32/10 && b > math.MaxInt32%10)) {
			y = math.MaxInt32
			break
		}
		if sign < 0 && (y < math.MinInt32/10 || (y == math.MinInt32/10 && b < math.MinInt32%10)) {
			y = math.MinInt32
			break
		}
		y = y*10 + b
		i++
	}

	return y
}
