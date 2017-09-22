package main

import (
	"math"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var i int

func bstFromPreorder(v []int) *TreeNode {
	i = 0
	return build(v, math.MaxInt32)
}

func build(v []int, bound int) *TreeNode {
	if i < len(v) && v[i] <= bound {
		node := TreeNode{Val: v[i]}
		i++
		node.Left = build(v, node.Val)
		node.Right = build(v, bound)
		return &node
	}
	return nil
}
