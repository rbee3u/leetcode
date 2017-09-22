func longestPalindrome(s string) string {
	n := 2 * len(s)
	asymmetric := func(center int, radius int) bool {
		return center < radius || center+radius > n ||
			(center%2 != radius%2 && s[(center-radius)/2] != s[(center+radius)/2])
	}
	preCenter, preRadius, maxCenter, maxRadius := 0, 0, 0, 0
	p := make([]int, n)
	for i := 1; i < n; i++ {
		if distance := i - preCenter; distance <= preRadius {
			if p[preCenter-distance] < preRadius-distance {
				p[i] = p[preCenter-distance]
			} else {
				p[i] = preRadius - distance
			}
		}
		for !asymmetric(i, p[i]+1) {
			p[i] += 1
		}
		if preCenter+preRadius < i+p[i] {
			preCenter, preRadius = i, p[i]
		}
		if maxRadius < preRadius {
			maxCenter, maxRadius = preCenter, preRadius
		}
	}
	return s[(maxCenter-maxRadius)/2 : (maxCenter+maxRadius)/2]
}
