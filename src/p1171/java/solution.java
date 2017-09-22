class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode sentinel = new ListNode(0);
        sentinel.next = head;
        HashMap<Integer, ListNode> last = new HashMap<>();
        int total = 0;
        for (ListNode p = sentinel; p != null; p = p.next) {
            total += p.val;
            last.put(total, p);
        }
        total = 0;
        for (ListNode p = sentinel; p != null; p = p.next) {
            total += p.val;
            p.next = last.get(total).next;
        }
        return sentinel.next;
    }
}
