package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func pathSum(root *TreeNode, sum int) (ans int) {
	mem := make(map[int]int)
	mem[0] = 1
	traverse(root, sum, 0, mem, &ans)
	return ans
}

func traverse(node *TreeNode, target int, current int, mem map[int]int, ans *int) {
	if node == nil {
		return
	}
	current = current + node.Val
	*ans = *ans + mem[current-target]
	mem[current] = mem[current] + 1
	traverse(node.Left, target, current, mem, ans)
	traverse(node.Right, target, current, mem, ans)
	mem[current] = mem[current] - 1
}