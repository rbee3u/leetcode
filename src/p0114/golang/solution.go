package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func flatten(root *TreeNode) {
	flattenWithTail(root)
}

func flattenWithTail(node *TreeNode) (tail *TreeNode) {
	if node == nil {
		return nil
	}
	if node.Left == nil {
		if node.Right == nil {
			return node
		}
		return flattenWithTail(node.Right)
	}
	leftTail := flattenWithTail(node.Left)
	leftTail.Right = node.Right
	node.Right = node.Left
	node.Left = nil
	return flattenWithTail(node.Right)
}