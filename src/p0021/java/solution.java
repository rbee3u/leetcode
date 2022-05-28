class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode sentinel = new ListNode(0), p = sentinel;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                p = p.next = l1;
                l1 = l1.next;
            } else {
                p = p.next = l2;
                l2 = l2.next;
            }
        }
        if (l1 != null) {
            p.next = l1;
        }
        if (l2 != null) {
            p.next = l2;
        }
        return sentinel.next;
    }
}
