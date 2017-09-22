package main

func findJudge(n int, trusts [][]int) int {
	degree := make([]int, n + 1)
	for _, trust := range trusts {
		degree[trust[0]]--
		degree[trust[1]]++
	}
	for i := 1; i <= n; i++ {
		if degree[i] == n - 1 {
			return i
		}
	}
	return -1
}
