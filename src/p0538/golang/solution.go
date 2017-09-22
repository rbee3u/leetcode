package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func convertBST(root *TreeNode) *TreeNode {
	if root != nil {
		acc := 0
		inorderTraversal(root, &acc)
	}
	return root
}

func inorderTraversal(node *TreeNode, acc *int) {
	if node.Right != nil {
		inorderTraversal(node.Right, acc)
	}
	node.Val, *acc = node.Val + (*acc), *acc + node.Val
	if node.Left != nil {
		inorderTraversal(node.Left, acc)
	}
}
