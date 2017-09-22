package main

func maxCoins(nums []int) int {
	xs := []int{1}
	for _, x := range nums {
		if x > 0 {
			xs = append(xs, x)
		}
	}
	xs = append(xs, 1)
	n := len(xs)
	dp := [][]int(nil)
	for i := 0; i < n; i++ {
		dp = append(dp, make([]int, n))
	}
	return burst(xs, dp, 1, n-2)
}

func burst(xs []int, dp [][]int, left int, right int) (ans int) {
	if left > right {
		return 0
	}
	if dp[left][right] > 0 {
		return dp[left][right]
	}
	for last := left; last <= right; last++ {
		tmp := xs[left-1]*xs[last]*xs[right+1] +
			burst(xs, dp, left, last-1) +
			burst(xs, dp, last+1, right)
		if ans < tmp {
			ans = tmp
		}
	}
	dp[left][right] = ans
	return ans
}
