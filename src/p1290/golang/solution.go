func getDecimalValue(head *ListNode) int {
	result := 0
	for p := head; p != nil; p = p.Next {
		result = result*2 + p.Val
	}
	return result
}
