func removeNthFromEnd(head *ListNode, n int) *ListNode {
	sentinel := ListNode{Next: head}
	first := &sentinel
	for i := 0; i < n; i++ {
		first = first.Next
	}
	second := &sentinel
	for first.Next != nil {
		first = first.Next
		second = second.Next
	}
	removeNode := second.Next
	second.Next = removeNode.Next
	return sentinel.Next
}
