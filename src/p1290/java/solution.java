class Solution {
    public int getDecimalValue(ListNode head) {
        int result = 0;
        for (ListNode p = head; p != null; p = p.next) {
            result = result * 2 + p.val;
        }
        return result;
    }
}
