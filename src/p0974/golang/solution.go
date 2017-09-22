package main

func subarraysDivByK(A []int, K int) (ans int) {
	groups := make([]int, K)
	groups[0] = 1
	sum := 0
	for _, x := range A {
		sum += x
		r := (sum % K + K) % K
		ans += groups[r]
		groups[r]++
	}
	return ans
}
