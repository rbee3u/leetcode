class Solution:
    def rangeSumBST(self, root: TreeNode, l: int, r: int) -> int:
        if not root:
            return 0
        if r < root.val:
            return self.rangeSumBST(root.left, l, r)
        if l > root.val:
            return self.rangeSumBST(root.right, l, r)
        return root.val + self.rangeSumBST(root.left, l, r) + self.rangeSumBST(root.right, l, r)
