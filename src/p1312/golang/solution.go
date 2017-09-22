func minInsertions(s string) int {
	n := len(s)
	dp := make([]int, n+1)
	for i := n - 2; i >= 0; i-- {
		prev := 0
		for j := i + 2; j <= n; j++ {
			temp := dp[j]
			if s[i] == s[j-1] {
				dp[j] = prev
			} else {
				if dp[j] > dp[j-1] {
					dp[j] = 1 + dp[j-1]
				} else {
					dp[j] = 1 + dp[j]
				}
			}
			prev = temp
		}
	}
	return dp[n]
}
