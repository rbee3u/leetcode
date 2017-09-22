class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode sentinel = new ListNode(0);
        sentinel.next = head;
        ListNode first = sentinel;
        for (int i = 0; i < n; i++) {
            first = first.next;
        }
        ListNode second = sentinel;
        while (first.next != null) {
            first = first.next;
            second = second.next;
        }
        ListNode removeNode = second.next;
        second.next = removeNode.next;
        return sentinel.next;
    }
}
