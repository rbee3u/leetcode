package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	value := preorder[0]
	pivot := 0
	for inorder[pivot] != value {
		pivot++
	}
	node := &TreeNode{
		Val: value,
	}
	node.Left = buildTree(preorder[1:pivot+1], inorder[:pivot])
	node.Right = buildTree(preorder[pivot+1:], inorder[pivot+1:])
	return node
}

