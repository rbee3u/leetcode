package main

func subsets(nums []int) (results [][]int) {
	n := len(nums)
	if len(nums) == 0 {
		return [][]int{nil}
	}
	init, last := nums[:n-1], nums[n-1]
	as := subsets(init)
	bs := subsets(init)
	for i := range bs {
		bs[i] = append(bs[i], last)
	}
	return append(as, bs...)
}
