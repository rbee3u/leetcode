class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        sentinel = TreeNode(0)
        sentinel.right = root
        prev, curr = sentinel, root
        while curr is not None and curr.val > val:
            prev = curr
            curr = curr.right
        prev.right = TreeNode(val)
        prev.right.left = curr
        return sentinel.right
