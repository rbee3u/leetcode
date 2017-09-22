func removeZeroSumSublists(head *ListNode) *ListNode {
	sentinel := ListNode{Next: head}
	last := make(map[int]*ListNode)
	total := 0
	for p := &sentinel; p != nil; p = p.Next {
		total += p.Val
		last[total] = p
	}
	total = 0
	for p := &sentinel; p != nil; p = p.Next {
		total += p.Val
		p.Next = last[total].Next
	}
	return sentinel.Next
}
