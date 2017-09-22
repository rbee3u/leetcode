func rangeSumBST(root *TreeNode, L int, R int) int {
	if root == nil {
		return 0
	}
	if R < root.Val {
		return rangeSumBST(root.Left, L, R)
	}
	if L > root.Val {
		return rangeSumBST(root.Right, L, R)
	}
	return root.Val + rangeSumBST(root.Left, L, R) + rangeSumBST(root.Right, L, R)
}
