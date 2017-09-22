class Solution {
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        TreeNode sentinel = new TreeNode(0); sentinel.right = root;
        TreeNode prev = sentinel, curr = root;
        while (curr != null && curr.val > val) {
            prev = curr; curr = curr.right;
        }
        prev.right = new TreeNode(val);
        prev.right.left = curr;
        return sentinel.right;
    }
}
