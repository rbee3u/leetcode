package main

import (
	"fmt"
	"hash/crc32"
)

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

var subtrees = make(map[int][]*TreeNode)
var crc32q = crc32.MakeTable(0xD5828281)
func calcHash(n *TreeNode, cache bool) int {
	if n == nil {
		return 0
	}
	var left, right string
	if n.Left != nil {
		left = fmt.Sprintf("%d", calcHash(n.Left, cache))
	}
	if n.Right != nil {
		right = fmt.Sprintf("%d", calcHash(n.Right, cache))
	}
	bytes := []byte(fmt.Sprintf("%s|%d|%s", left, n.Val, right))
	hash := int(crc32.Checksum(bytes, crc32q))
	if cache {
		subtrees[hash] = append(subtrees[hash], n)
	}
	return hash
}

func isSame(r *TreeNode, t *TreeNode) bool {
	if r == nil && t == nil {
		return true
	}
	if r != nil && t == nil {
		return false
	}
	if r == nil && t != nil {
		return false
	}
	if r.Val != t.Val {
		return false
	}
	return isSame(r.Left, t.Left) && isSame(r.Right, t.Right)
}

func isSubtree(s *TreeNode, t *TreeNode) bool {
	subtrees = make(map[int][]*TreeNode)
	calcHash(s, true)
	hash := calcHash(t, false)
	for _, r := range subtrees[hash] {
		if isSame(r, t) {
			return true
		}
	}
	return false
}


