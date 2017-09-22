package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minCameraCover(root *TreeNode) int {
	if root == nil {
		return 0
	}
	_, y, z := traversal(root)
	return min(y, z)
}

//  (x)    (y)    (z)
//   0      0      1
//  / \    / \    / \
// 0   0  1   *  *   *
func traversal(root *TreeNode) (x int, y int, z int) {
	x, y, z = 0x3fffffff, 0x3fffffff, 0x3fffffff
	switch {
	case root.Left == nil && root.Right == nil:
		x, z = 0, 1
	case root.Left == nil && root.Right != nil:
		rx, ry, rz := traversal(root.Right)
		x, y, z = min(x, ry), min(y, rz), min(z, rx+1, ry+1, rz+1)
	case root.Left != nil && root.Right == nil:
		lx, ly, lz := traversal(root.Left)
		x, y, z = min(x, ly), min(y, lz), min(z, lx+1, ly+1, lz+1)
	case root.Left != nil && root.Right != nil:
		lx, ly, lz := traversal(root.Left)
		rx, ry, rz := traversal(root.Right)
		x = min(x, ly+ry)
		y = min(y, ly+rz, lz+ry, lz+rz)
		z = min(z, lx+rx+1, lx+ry+1, lx+rz+1, ly+rx+1, ly+ry+1, ly+rz+1, lz+rx+1, lz+ry+1, lz+rz+1)
	}
	return x, y, z
}

func min(head int, tail ...int) int {
	for _, elem := range tail {
		if head > elem {
			head = elem
		}
	}
	return head
}
