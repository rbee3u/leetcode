func longestCommonPrefix(v []string) string {
	if len(v) == 0 {
		return ""
	}
	result := []byte(nil)
	for i := 0; ; i++ {
		for j := 0; j < len(v); j++ {
			if i >= len(v[j]) || v[j][i] != v[0][i] {
				return string(result)
			}
		}
		result = append(result, v[0][i])
	}
}
