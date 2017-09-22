package main

func countSubstrings(s string) int {
	n := 2 * len(s)
	count := int(0)
	center, right := 0, 0
	dp := make([]int, n)
	for i := 1; i < n; i++ {
		k := 0
		if i < right {
			k = dp[2*center-i]
			if k > right-i {
				k = right - i
			}
		}
		for equal(s, n, i-k-1, i+k+1) {
			k++
		}
		if i+k > right {
			center, right = i, i+k
		}
		dp[i] = k
		count += (k + 1) / 2
	}
	return count
}

func equal(s string, n int, x int, y int) bool {
	if x < 0 || n < x {
		return false
	}
	if y < 0 || n < y {
		return false
	}
	if x%2 == 1 && y%2 == 1 {
		return s[x/2] == s[y/2]
	}
	if x%2 == 0 && y%2 == 0 {
		return true
	}
	return false
}
