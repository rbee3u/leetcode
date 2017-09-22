func fourSum(nums []int, target int) (result [][]int) {
	sort.Ints(nums)
	n := len(nums)
	for i := 0; i+3 < n; i++ {
		if i > 0 && nums[i-1] == nums[i] {
			continue
		}
		if nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target {
			break
		}
		if nums[i]+nums[n-3]+nums[n-2]+nums[n-1] < target {
			continue
		}
		for j := i + 1; j+2 < n; j++ {
			if j > i+1 && nums[j-1] == nums[j] {
				continue
			}
			if nums[i]+nums[j]+nums[i+1]+nums[i+2] > target {
				break
			}
			if nums[i]+nums[j]+nums[n-2]+nums[n-1] < target {
				continue
			}
			sum2 := nums[i] + nums[j]
			for p, q := j+1, n-1; p < q; {
				sum4 := sum2 + nums[p] + nums[q]
				if sum4 < target {
					p++
				} else if sum4 > target {
					q--
				} else {
					result = append(result, []int{nums[i], nums[j], nums[p], nums[q]})
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
	}
	return result
}
