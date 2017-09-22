package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func diameterOfBinaryTree(root *TreeNode) int {
	diameter, _ := diameterAndHeight(root)
	return diameter
}

func diameterAndHeight(node *TreeNode) (diameter int, height int) {
	if node == nil {
		return 0, 0
	}
	leftDiameter, leftHeight := diameterAndHeight(node.Left)
	rightDiameter, rightHeight := diameterAndHeight(node.Right)
	height = leftHeight + 1
	if height < rightHeight + 1 {
		height = rightHeight + 1
	}
	diameter = leftHeight + rightHeight
	if diameter < leftDiameter {
		diameter = leftDiameter
	}
	if diameter < rightDiameter {
		diameter = rightDiameter
	}
	return diameter, height
}