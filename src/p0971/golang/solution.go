package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func flipMatchVoyage(root *TreeNode, voyage []int) []int {
	ctx := &context{
		voyage: voyage,
		answer: []int(nil),
	}
	traverse(root, ctx)
	return ctx.answer
}

type context struct {
	voyage []int
	answer []int
}

func traverse(node *TreeNode, ctx *context) {

	if len(ctx.answer) == 1 && ctx.answer[0] == -1 {
		return
	}

	if node == nil {
		return
	}

	if node.Val != ctx.voyage[0] {
		ctx.answer = []int{-1}
		return
	}

	if node.Left != nil && node.Right != nil && node.Right.Val == ctx.voyage[1] {
		ctx.answer = append(ctx.answer, node.Val)
		node.Left, node.Right = node.Right, node.Left
	}

	ctx.voyage = ctx.voyage[1:]
	traverse(node.Left, ctx)
	traverse(node.Right, ctx)

}

