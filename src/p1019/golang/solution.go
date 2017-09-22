func nextLargerNodes(head *ListNode) (result []int) {
	for p := head; p != nil; p = p.Next {
		result = append(result, p.Val)
	}
	stk, top := make([]int, len(result)), 0
	for i, val := range result {
		for top > 0 && result[stk[top-1]] < val {
			result[stk[top-1]], top = val, top-1
		}
		stk[top], top = i, top+1
	}
	for top > 0 {
		result[stk[top-1]], top = 0, top-1
	}
	return result
}
