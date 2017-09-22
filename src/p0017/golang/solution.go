var n2s = []string{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}

func letterCombinations(digits string) (result []string) {
	if len(digits) > 0 {
		dfs(digits, 0, "", &result)
	}
	return result
}

func dfs(digits string, i int, s string, result *[]string) {
	if i == len(digits) {
		*result = append(*result, s)
		return
	}
	button := n2s[digits[i]-'0']
	for p := 0; p < len(button); p++ {
		dfs(digits, i+1, s+button[p:p+1], result)
	}
}
