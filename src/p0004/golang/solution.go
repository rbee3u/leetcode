func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	total := len(nums1) + len(nums2)
	kth := (total + 1) / 2
	begin := max(kth, len(nums2)) - len(nums2)
	end := min(kth, len(nums1))
	for begin < end {
		i := begin + (end-begin)/2
		j := kth - i
		if nums1[i]-nums2[j-1] < 0 {
			begin = i + 1
		} else {
			end = i
		}
	}
	i := begin
	j := kth - i
	var left int
	switch {
	case j == 0:
		left = nums1[i-1]
	case i == 0:
		left = nums2[j-1]
	default:
		left = max(nums1[i-1], nums2[j-1])
	}
	if total%2 != 0 {
		return float64(left)
	}
	var right int
	switch {
	case j == len(nums2):
		right = nums1[i]
	case i == len(nums1):
		right = nums2[j]
	default:
		right = min(nums1[i], nums2[j])
	}
	return float64(left+right) / 2
}

func min(x int, y int) int {
	if x < y {
		return x
	}
	return y
}

func max(x int, y int) int {
	if x > y {
		return x
	}
	return y
}
