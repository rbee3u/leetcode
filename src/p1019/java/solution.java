class Solution {
    public int[] nextLargerNodes(ListNode head) {
        ArrayList<Integer> result = new ArrayList<>();
        for (ListNode p = head; p != null; p = p.next) {
            result.add(p.val);
        }
        int[] stk = new int[result.size()];
        int top = 0;
        for (int i = 0; i < result.size(); i++) {
            while (top > 0 && result.get(stk[top - 1]) < result.get(i)) {
                result.set(stk[--top], result.get(i));
            }
            stk[top++] = i;
        }
        while (top > 0) result.set(stk[--top], 0);
        return result.stream().mapToInt(i -> i).toArray();
    }
}
