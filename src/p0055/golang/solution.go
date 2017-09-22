package main

func canJump(nums []int) bool {
	reach := 0
	for i, num := range nums {
		if reach < i {
			break
		}
		if reach < i + num {
			reach = i + num
		}
	}
	return reach + 1 >= len(nums)
}
