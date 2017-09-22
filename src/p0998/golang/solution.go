package main

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func insertIntoMaxTree(root *TreeNode, val int) *TreeNode {
	sentinel := &TreeNode{Right: root}
	prev, curr := sentinel, root
	for curr != nil && curr.Val > val {
		prev, curr = curr, curr.Right
	}
	prev.Right = &TreeNode{Val: val, Left: curr}
	return sentinel.Right
}
