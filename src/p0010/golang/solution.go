func isMatch(s string, p string) bool {
	match := make([]bool, len(p)+1)
	for i := 0; i <= len(s); i++ {
		prev := match[0]
		match[0] = i == 0
		for j := 1; j <= len(p); j++ {
			if p[j-1] == '*' {
				prev, match[j] = match[j], match[j-2] || (match[j] && (p[j-2] == s[i-1] || p[j-2] == '.'))
			} else {
				prev, match[j] = match[j], prev && (p[j-1] == s[i-1] || p[j-1] == '.')
			}
		}
	}
	return match[len(p)]
}
