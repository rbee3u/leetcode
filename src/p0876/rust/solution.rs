impl Solution {
    pub fn middle_node(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut n, mut fast) = (0, head.as_ref());
        while let Some(t) = fast {
            fast = t.next.as_ref();
            n += 1;
        }
        let mut slow = head;
        while n >= 2 {
            slow = slow.unwrap().next;
            n -= 2;
        }
        return slow;
    }
}
