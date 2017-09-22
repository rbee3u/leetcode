package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isUnivalTree(root *TreeNode) (result bool) {
	result = true
	if root == nil {
		return result
	}
	traverse(root, root.Val, &result)
	return result
}

func traverse(root *TreeNode, unival int, result *bool) {
	if *result == false || root == nil {
		return
	}
	if root.Val != unival {
		*result = false
		return
	}
	traverse(root.Left, unival, result)
	traverse(root.Right, unival, result)
}