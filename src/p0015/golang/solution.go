
func threeSum(nums []int) (result [][]int) {
	sort.Ints(nums)
	n := len(nums)
	for i := 0; i+2 < n; i++ {
		if i > 0 && nums[i-1] == nums[i] {
			continue
		}
		if nums[i]+nums[i+1]+nums[i+2] > 0 {
			break
		}
		if nums[i]+nums[n-2]+nums[n-1] < 0 {
			continue
		}
		for p, q := i+1, n-1; p < q; {
			sum3 := nums[i] + nums[p] + nums[q]
			if sum3 < 0 {
				p++
			} else if sum3 > 0 {
				q--
			} else {
				result = append(result, []int{nums[i], nums[p], nums[q]})
				p++
				q--
				for p < q && nums[p-1] == nums[p] {
					p++
				}
				for p < q && nums[q] == nums[q+1] {
					q--
				}
			}
		}
	}
	return result
}
