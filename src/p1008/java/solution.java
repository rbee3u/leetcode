class Solution {
    public TreeNode bstFromPreorder(int[] v) {
        i = 0;
        return build(v, Integer.MAX_VALUE);
    }
    private int i;
    private TreeNode build(int[] v, int bound) {
        if (i < v.length && v[i] <= bound) {
            TreeNode node = new TreeNode(v[i++]);
            node.left = build(v, node.val);
            node.right = build(v, bound);
            return node;
        }
        return null;
    }
}
