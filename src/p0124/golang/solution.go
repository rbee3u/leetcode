package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var INT_MIN int = -0x80000000

func maxPathSum(root *TreeNode) (ans int) {
	ans = INT_MIN
	traverse(root, &ans)
	return ans
}

func traverse(node *TreeNode, ans *int) (sum int) {
	if node.Left == nil && node.Right == nil {
		sum = node.Val
		if *ans < sum {
			*ans = sum
		}
		return sum
	}
	leftSum := INT_MIN
	if node.Left != nil {
		leftSum = traverse(node.Left, ans) + node.Val
	}
	if leftSum < node.Val {
		leftSum = node.Val
	}
	rightSum := INT_MIN
	if node.Right != nil {
		rightSum = traverse(node.Right, ans) + node.Val
	}
	if rightSum < node.Val {
		rightSum = node.Val
	}
	sum = node.Val
	if sum < leftSum {
		sum = leftSum
	}
	if sum < rightSum {
		sum = rightSum
	}
	add := leftSum + rightSum - node.Val
	if *ans < add {
		*ans = add
	}
	return sum
}
