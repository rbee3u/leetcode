class Solution {
    public ListNode addTwoNumbers(ListNode a, ListNode b) {
        ListNode sentinel = new ListNode(0), tail = sentinel;
        for (int carry = 0; carry > 0 || a != null || b != null; carry /= 10) {
            if (a != null) {
                carry += a.val;
                a = a.next;
            }
            if (b != null) {
                carry += b.val;
                b = b.next;
            }
            tail = tail.next = new ListNode(carry % 10);
        }
        return sentinel.next;
    }
}
