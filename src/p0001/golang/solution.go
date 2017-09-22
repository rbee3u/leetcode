func twoSum(nums []int, target int) []int {
	dict := map[int]int{}

	for j, y := range nums {
		if i, ok := dict[target-y]; ok {
			return []int{i, j}
		}

		dict[y] = j
	}

	return []int{}
}
