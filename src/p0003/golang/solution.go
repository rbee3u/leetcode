func lengthOfLongestSubstring(s string) int {
	result := 0
	count := make([]int, 256)

	for i, j := 0, 0; j < len(s); j++ {
		for count[s[j]]++; count[s[j]] > 1; i++ {
			count[s[i]]--
		}

		if result < j+1-i {
			result = j + 1 - i
		}
	}

	return result
}
