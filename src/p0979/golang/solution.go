package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func distributeCoins(root *TreeNode) int {
	_, moves := traverse(root)
	return moves
}

func traverse(node *TreeNode) (value int, moves int) {
	if node == nil {
		return 0, 0
	}
	lhsValue, lhsMoves := traverse(node.Left)
	rhsValue, rhsMoves := traverse(node.Right)
	sumValue := node.Val + lhsValue + rhsValue
	sumMoves := abs(1 - sumValue) + lhsMoves + rhsMoves
	return sumValue, sumMoves
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}