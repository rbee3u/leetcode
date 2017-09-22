from typing import List
import math


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def bstFromPreorder(self, v: List[int]) -> TreeNode:
        self.i = 0
        return self.build(v, math.inf)

    def build(self, v, bound):
        if self.i < len(v) and v[self.i] <= bound:
            node = TreeNode(v[self.i])
            self.i += 1
            node.left = self.build(v, node.val)
            node.right = self.build(v, bound)
            return node
        return None


