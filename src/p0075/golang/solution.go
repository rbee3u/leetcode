package main

func sortColors(nums []int)  {
	n := len(nums)
	i, j, k := -1, 0, n
	for j < k {
		if nums[j] == 1 {
			j++
			continue
		}
		if nums[j] == 0 {
			i++
			nums[i], nums[j] = nums[j], nums[i]
			j++
			continue
		}
		if nums[j] == 2 {
			k--
			nums[k], nums[j] = nums[j], nums[k]
			continue
		}
	}
}
