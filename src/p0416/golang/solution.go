package main

func canPartition(nums []int) bool {
	v := 0
	for _, x := range nums {
		v = v + x
	}
	if v % 2 == 1 {
		return false
	}
	v = v / 2
	dp := make([]bool, v + 1)
	dp[0] = true
	for _, x := range nums {
		for u := v; u >= x; u-- {
			dp[u] = dp[u] || dp[u-x]
		}
	}
	return dp[v]
}
