func reverse(x int) (y int) {
	for ; x != 0; x /= 10 {
		if x > 0 && (y > math.MaxInt32/10 || (y == math.MaxInt32/10 && x%10 > math.MaxInt32%10)) {
			y = 0
			break
		}
		if x < 0 && (y < math.MinInt32/10 || (y == math.MinInt32/10 && x%10 < math.MinInt32%10)) {
			y = 0
			break
		}
		y = y*10 + x%10
	}
	return y
}
