func addTwoNumbers(a *ListNode, b *ListNode) *ListNode {
	var (
		sentinel ListNode
		tail     = &sentinel
	)

	for carry := 0; carry != 0 || a != nil || b != nil; carry /= 10 {
		if a != nil {
			carry, a = carry+a.Val, a.Next
		}

		if b != nil {
			carry, b = carry+b.Val, b.Next
		}

		tail.Next = &ListNode{Val: carry % 10}
		tail = tail.Next
	}

	return sentinel.Next
}
