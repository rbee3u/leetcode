package main

func numsSameConsecDiff(n int, k int) (ans []int) {
	if n == 1 {
		return []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	}
	for x := 1; x <= 9; x++ {
		dfs(x, n-1, k, &ans)
	}
	return ans
}

func dfs(x int, n int, k int, ans *[]int) {
	if n == 0 {
		*ans = append(*ans, x)
		return
	}
	b := x % 10
	if b+k <= 9 {
		dfs(x*10+b+k, n-1, k, ans)
	}
	if k != 0 && b-k >= 0 {
		dfs(x*10+b-k, n-1, k, ans)
	}
}
