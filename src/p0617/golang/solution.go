package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
	if t1 != nil && t2 != nil {
		return &TreeNode{
			Val: t1.Val + t2.Val,
			Left: mergeTrees(t1.Left, t2.Left),
			Right: mergeTrees(t1.Right, t2.Right),
		}
	} else if t1 != nil && t2 == nil {
		return &TreeNode{
			Val: t1.Val,
			Left: mergeTrees(t1.Left, nil),
			Right: mergeTrees(t1.Right, nil),
		}
	} else if t1 == nil && t2 != nil {
		return &TreeNode{
			Val: t2.Val,
			Left: mergeTrees(nil, t2.Left),
			Right: mergeTrees(nil, t2.Right),
		}
	} else {
		return nil
	}
}
