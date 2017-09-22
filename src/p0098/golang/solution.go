package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isValidBST(root *TreeNode) bool {
	valid := true
	prev, isset := 0, false
	inorder(root, &prev, &isset, &valid)
	return valid
}

func inorder(node *TreeNode, prev *int, isset *bool, valid *bool) {
	if node == nil {
		return
	}
	if !*valid {
		return
	}
	inorder(node.Left, prev, isset, valid)
	if *isset && *prev >= node.Val {
		*valid = false
		return
	}
	*isset = true
	*prev = node.Val
	inorder(node.Right, prev, isset, valid)
}
