package main

func minDistance(word1 string, word2 string) int {
	n, m := len(word1), len(word2)
	dp := [][]int(nil)
	for i := 0; i <= n; i++ {
		dp = append(dp, make([]int, m+1))
	}
	for i := 1; i <= n; i++ {
		dp[i][0] = i
	}
	for j := 1; j <= m; j++ {
		dp[0][j] = j
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if word1[i-1] == word2[j-1] {
				dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]+1, dp[i][j-1]+1)
			} else {
				dp[i][j] = min(dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1)
			}
		}
	}
	return dp[n][m]
}

func min(head int, tail ...int) int {
	for _, elem := range tail {
		if head > elem {
			head = elem
		}
	}
	return head
}